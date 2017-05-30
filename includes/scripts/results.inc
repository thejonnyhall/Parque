<?

if (!isset($_GET['lat'])){
    if (isset($_GET['submit'])) {
        global $database;
        try {
            $query =
            "SELECT id, name, suburb, latitude, longitude, review, AVG(rating) AS avgRating
            FROM items
            LEFT JOIN reviews ON items.id = reviews.parkID
            WHERE name LIKE ";

            if (isset($_GET['name'])) {
                $inputName = $_GET['name'];
                $stmt = $database->prepare($query. "'%$inputName%' GROUP BY id");
            }

            if (isset($_GET['suburb'])) {
                $inputSuburb = $_GET['suburb'];
                $stmt = $database->prepare($query. "'%$inputName%'" . " AND suburb = '$inputSuburb' GROUP BY id");
            }

            if (isset($_GET['rating'])) {

                $inputRating = $_GET['rating'];
                $stmt = $database->prepare($query. "'%$inputName%'" . " GROUP BY id HAVING AVG(rating) >= $inputRating");
            }


            if (isset($_GET['suburb']) && isset($_GET['rating'])) {
                $inputSuburb = $_GET['suburb'];
                $inputRating = $_GET['rating'];
                $stmt = $database->prepare($query. "'%$inputName%'" . " AND suburb = '$inputSuburb' GROUP BY id HAVING AVG(rating) >= $inputRating");
            }
            // Come back to this Because i think i should change it to not Prepare in every query.
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


                $destination = "itemResult.php?id={$parks['id']}";
                echo "<tr>
                <td><a href='$destination'>" . htmlspecialchars($name) . "</td>
                <td>" . htmlspecialchars($suburb) . "</td>
                <td>" . htmlspecialchars(round($rating)) . "</td>
            </tr>";
            }
            ?>
            <script>displayMarkers(<?php echo json_encode($results) ?>);</script>
            <?php
        } catch (Exception $e) {
            echo "exceptional xD";
            echo $e->getMessage();
        }
    }
}

?>
