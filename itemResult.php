<? require "./includes/partials/header.inc"; ?>
<? require "./includes/partials/navigation.inc"; ?>
<? require "./includes/scripts/itemResult.inc"; ?>
<? require "./includes/scripts/common.inc"; ?>
<!--	These variables are global variables used for the map-->
	<script type="text/javascript">
        var map;
        var bounds;
    </script>
	<script async defer
	src="https://maps.googleapis.com/maps/api/js?key=AIzaSyDFdqpcCyNQSmIGuIOZyNKOfKjvqp0Vv3Q&callback=initMap">
	</script>

<!-- Not sure but i think maps finally works?? -->
<? echo "<h1>$name</h1>"; ?>
<div id="map"></div>

<br>
    <div class="userreviews">
        <? require "./includes/scripts/review.inc"; ?>
    </div>
    <br>
    <div class="parkinfo">
        <h3>Park info</h3>
        <table id="resulttable" border="3" >
            <colgroup span="1"></colgroup>
            <tr>
                <th>Park Name</th>
                <td><? echo $name; ?></td>
            </tr>
            <tr>
                <th>Suburb</th>
                <td><? echo $suburb; ?></td>
            </tr>
            <tr>
                <th>Average Rating</th>
                <td><?
                if (round($rating) == '5') {
                    echo "&#9733 &#9733 &#9733 &#9733 &#9733;<br>";
                } else if (round($rating) == '4') {
                    echo "&#9733 &#9733 &#9733 &#9733;";
                } else if (round($rating) == '3') {
                    echo "&#9733 &#9733 &#9733;";
                } else if (round($rating) == '2') {
                    echo "&#9733 &#9733;";
                } else if (round($rating) == '1') {
                    echo "&#9733;";
                } else {
                    echo "This Park is not yet rated";
                }?>
                </div></td>
            </tr>
        </table>
    </div>
<?
if($_SESSION) { ?>
    <div class="leaveAReview">
        <br>
        <form action="" method="post">
            <!-- Username grabbed from the Session firstName to add to review -->
            <input type="text" visibility : hidden name="username" value="<? echo $_SESSION['firstName'] ?>" readonly>
            <div class="stars">
                <input type="radio" id="5-stars" name="rating" value="5" />
                <label for="5-stars" class="star">&#9733;</label>
                <input type="radio" id="4-stars" name="rating" value="4" />
                <label for="4-stars" class="star">&#9733;</label>
                <input type="radio" id="3-stars" name="rating" value="3" />
                <label for="3-stars" class="star">&#9733;</label>
                <input type="radio" id="2-stars" name="rating" value="2" />
                <label for="2-stars" class="star">&#9733;</label>
                <input type="radio" id="1-star" name="rating" value="1" />
                <label for="1-star" class="star">&#9733;</label>
            </div>
            <textarea name="review" cols="50" rows="5" required placeholder="Write a review!"></textarea>
            <br>
            <input type="submit" name="postReview" value="Post Review">
        </form>
    </div>
<?
} else {
    echo "<br /> <br /> <br /> <br /> <br />";
    echo "<a href='login.php'>Login to Leave a review</a>";
} ?>
    <br><br><br><br><br><br><br><br><br><br><br><br>
