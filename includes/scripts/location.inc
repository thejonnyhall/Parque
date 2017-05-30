<?php if (isset($_GET['lat'])){
    global $database;

    $latitude = $_GET['lat'];
    $longitude = $_GET['lng'];

    $query =
    "SELECT id, name, suburb, latitude, longitude, review, AVG(rating) AS avgRating
    FROM items
    LEFT JOIN reviews ON items.id = reviews.parkID
    WHERE (ACOS(SIN(RADIANS(`latitude`)) * SIN( RADIANS($latitude)) + COS(RADIANS(`latitude`)) * COS(RADIANS( $latitude)) * COS(RADIANS(`longitude`) - RADIANS($longitude))) * 6380) <= 5
    GROUP BY id";

    $stmt = $database->prepare($query);

    $stmt->execute();

    $results = $stmt -> fetchAll();
    foreach ($results as $parks) {
        $parkID = $parks['id'];
        $name = $parks['name'];
        $suburb = $parks['suburb'];
        $lat = $parks['latitude'];
        $lon = $parks['longitude'];
        $review = $parks['review'];
        $rating = $parks['avgRating'];

        $parkArray = [$lat, $lon, $name, $parkID, $rating, $suburb];
    //<script>addMarkerToMap(<?php echo json_encode($parkArray); ? >);</script>

        $position = ["lat" => $latitude, "lon" => $longitude];
        $destination = "itemResult.php?id={$parks['id']}";
        echo "<tr>
        <td><a href='$destination'>" . htmlspecialchars($name) . "</td>
        <td>" . htmlspecialchars($suburb) . "</td>
        <td>" . htmlspecialchars($rating) . "</td>
    </tr>";
    }
    ?>
    <script>addTheBigMarker(<?php echo json_encode($position) ?>);</script>
    <script>displayMarkers(<?php echo json_encode($results) ?>);</script>
    <?php
}





?>
