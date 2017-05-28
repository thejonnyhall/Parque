<?
    global $database;
    try {
        $stmt = $database->prepare(
        "SELECT * FROM items
        LEFT JOIN reviews ON items.id = reviews.parkID
        WHERE ");
        $stmt->execute();

        $parks = $stmt->fetchAll();
        echo "exe";
;
    } catch (Exception $e) {
        $e->getMessage();
    }






function display_map($parks){
    // Set up and init an empty map
    echo '<div class="map" id="map"></div>';
    echo '<script>initMap();</script>';

    // Add each park as a marker on the map
    foreach($parks as $park){
        echo '<script>addMarkerToMap('.$park['latitude'].','.$park['longitude'].
            ',"'.$park['name'].'","park.php?id='.$park['parkid'].
            '","'.$park['rating'].'","'.$park['suburb'].
            '","'.$park['street'].'");</script>';
    }
}
?>
