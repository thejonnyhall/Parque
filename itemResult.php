<? require "./includes/partials/header.inc"; ?>
<? require "./includes/partials/navigation.inc"; ?>
<? require "./includes/scripts/itemResult.inc"; ?>

<? echo "<h1>$name</h1>"; ?>
<script>
<div id="map"></div>
initMap();
</script>

    <img src="./public/css/images/testmap.png" alt="testmap" width="390" height="300" align="left">
    <div class="userreviews">
        <h1>Reviews</h1>
            <!-- Review 1 -->
            <article>
                <header>
                  <h4>Oswald Doring  3/04/2017  2 stars</h4>
                  <p>The park was disguisting, i hated every minute</p>
                </header>
            </article>
            <!-- Review 2 -->
            <article>
                <header>
                  <h4>Jonny Hall  1/02/2017  5 stars</h4>
                  <p>The park was amazing, perfect and beautiful. <br>Just like me</p>
                </header>
            </article>
            <!-- Review 3 -->
            <article>
                <header>
                  <h4>Hannah Cassell  3/04/2017  4 stars</h4>
                  <p>Hey this isn't to do with Parks, but Jonny Hall if you see this call me on 0401237508 xx</p>
                </header>
            </article>
        </article>
    </div>
    <br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
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
                <td><div class="resultStars">
                    <label for="5-stars" >&#9733;</label>
                    <label for="4-stars" >&#9733;</label>
                    <label for="3-stars" >&#9733;</label>
                    <label for="2-stars" >&#9733;</label>
                    <!-- <label for="1-star" >&#9733;</label> -->
                </div></td>
            </tr>
        </table>
    </div>
    <div class="leaveAReview">
        <br>
        <form action="lazucc.html">
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
            <textarea name="review" cols="50" rows="5" placeholder="Write a review!"></textarea>
            <br>
            <input type="submit" value="Submit">
        </form>
    </div>
    <br><br><br><br><br><br><br><br><br><br><br><br><br>
    </div>
