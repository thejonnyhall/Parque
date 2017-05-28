<?php
$resultsSearch = $database -> prepare("SELECT items.id AS id, name, suburb, COALESCE(Rating, 0) AS Rating
    FROM items LEFT JOIN reviews ON items.id = reviews.parkID
    WHERE Name LIKE :nameSearch AND Suburb = :suburb
    GROUP BY Name
    HAVING Rating >= :rating");

$resultsSearch -> bindValue(":suburb", $_GET['suburb']);
$resultsSearch -> bindValue(":rating", $_GET['rating']);

$resultsSearch -> execute();

foreach ($resultsSearch as $row) {
    $ratingString = str_repeat("&#9733;", $row["Rating"]);
    $ratingString .= str_repeat("&#9734;", 5 - $row["Rating"]);

    echo '<hr><li>
        <div class="details">
            <a href="park.php?id=' . $row["id"] . '"><p class="park-name">' . $row["Name"] . '</p></a>
            <p class="location">' . $row["Suburb"] . '</p>
            <p class="rating">' . $ratingString . '</p>
        </div>
    </li>';
}

if ($resultsSearch -> rowCount() == 0) {
    echo "<h3>No results found, please search again.</h3>";
}
?>
