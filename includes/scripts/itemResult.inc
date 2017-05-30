<?php
if (isset($_GET['id'])) {
    global $database;
    try {
        $id = $_GET['id'];
        $stmt = $database->prepare("SELECT id, name, suburb, longitude, latitude, AVG(rating) AS avgRating, review
            FROM items
            LEFT JOIN reviews ON items.id = reviews.parkID
            WHERE items.id = $id");
        $stmt->execute();

        $parks = $stmt->fetch();
        $parkID = $parks['id'];
        $name = $parks['name'];
        $suburb = $parks['suburb'];
        $lon = $parks['longitude'];
        $lat = $parks['latitude'];
        $rating = $parks['avgRating'];
        $review = $parks['review'];
?>
        <script>
            var singleMap;
            function initMap(){
                singleMap = new google.maps.Map(document.getElementById('map'),{
                center:  {lat:<?php echo $lat ?>, lng:<?php echo $lon ?>},
                zoom: 15
                });
                var marker = new google.maps.Marker({
                    position: {lat:<?php echo $lat ?>, lng:<?php echo $lon ?>},
                    map: singleMap
                });
            };
        </script>
<?
    } catch (Exception $e) {
        echo "exceptional xD";
        echo $e->getMessage();
    }
}
