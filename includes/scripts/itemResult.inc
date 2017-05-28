<?
if (isset($_GET['id'])) {
    global $database;
    try {
        $id = $_GET['id'];
        $stmt = $database->prepare("SELECT * FROM items LEFT JOIN reviews ON parkID = id WHERE id = $id");
        $stmt->execute();

        $parks = $stmt->fetch();
        $parkID = $parks['id'];
        $name = $parks['name'];
        $suburb = $parks['suburb'];
        $lon = $parks['longitude'];
        $lat = $parks['latitude'];
        $rating = $parks['rating'];
        $review = $parks['review'];


        // $sql = $database->prepare("SELECT * FROM reviews LEFT JOIN members ON members.userID = reviews.userID where reviews.parkID = $id");
        // $sql->execute();
        //
        // $names = $sql->fetchAll();
        //
        // var_dump($names);
        // $firstname = $names['firstName'];

    } catch (Exception $e) {
        echo "exceptional xD";
        echo $e->getMessage();
    }
}




?>

<script type="text/javascript">
    lon = <? echo json_encode($lon); ?>;
    lat = <? echo json_encode($lat); ?>;
</script>
