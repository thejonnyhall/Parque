<?
if (isset($_GET['submit'])) {
    global $database;
    $query = "SELECT * FROM items WHERE name LIKE ";
    try {
        // Stores what the user types in the name box

        $name = $_GET['name'];
        $stmt = $database->prepare($query."'%$name%'");
        $stmt->execute();


        if (isset($_GET['suburb'])) {
            $suburb = $_GET['suburb'];
            $stmt = $database->prepare($query."'%$name%'" . "AND suburb = '$suburb'");
            $stmt->execute();
        }
        //
        // if (isset($_GET['rating'])) {
        //     $rating = $_GET['suburb'];
        //     $stmt = $database->prepare($query."'%$rating'" . "AND rating = '$rating'");
        //     $stmt->execute();
        // }


            $results = $stmt -> fetchAll();
            foreach ($results as $parks) {
                $name = $parks[2];
                $suburb = $parks[4];
                $lon = $parks[8];
                $lat = $parks[7];
                $destination = "itemResult.php?id={$parks['id']}";
                echo "<tr>
                <td><a href='$destination'>$name</td>
                <td>$suburb</td>
                <td>$lon, $lat</td>
            </tr>";
        }
    } catch (Exception $e) {
        echo "exceptional xD";
        echo $e->getMessage();
    }
}
?>
