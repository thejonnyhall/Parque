<?
if (isset($_GET['id'])) {
    global $database;
    try {
        $id = $_GET['id'];
        $stmt = $database->prepare("SELECT * FROM items WHERE id = $id");

        $stmt->execute();

        $results = $stmt -> fetchAll();
        foreach ($results as $parks) {
            $name = $parks[2];
            $suburb = $parks[4];
            $lon = $parks[8];
            $lat = $parks[7];
            $destination = "itemResult.php?id={$parks['id']}";
        }
    } catch (Exception $e) {
        echo "exceptional xD";
        echo $e->getMessage();
    }
}
?>
