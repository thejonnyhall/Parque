<? require "./includes/partials/header.inc"; ?>
<? require "./includes/partials/navigation.inc"; ?>
<? require "./includes/scripts/search.inc"; ?>

<div class="content">
    <h1>Search for a park</h1>
    <div>
        <!-- Search Form needs to be able to search based on: name, subrub, rating or location -->
        <form id="search" method="get" action="result.php">
            <input id="name" name="name" type="text" placeholder="Name">
            <p />

            <? // Dropdown suburb
            $query = $database->query("SELECT DISTINCT suburb FROM items ORDER BY suburb ASC");

            echo '<select id="suburb" name="suburb">';
            ?>
            <option value="" disabled selected>suburb</option>
            <?
            while ($row = $query->fetch(PDO::FETCH_ASSOC)) {
               echo '<option value="'.$row['suburb'].'">'.$row['suburb'].'</option>';
            }
            echo '</select>';
            ?>
            <p />

            <select id="rating" name="rating">
                <option value="0" disabled selected>Rating</option>
                <option value="1">1 Stars</option>
                <option value="2">2 Stars</option>
                <option value="3">3 Stars</option>
                <option value="4">4 Stars</option>
                <option value="5">5 Stars</option>
            </select>
            <p />
            <button type="submit" name="submit">Search</button>
        </form>



    </div>
<? require "./includes/partials/footer.inc"; ?>
