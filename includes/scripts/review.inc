<?
if (isset($_POST['postReview'])) {
	try {
		$parkID = $_GET['id'];
		$review = $_POST['review'];
		$rtng = $_POST['rating'];
		$username = $_POST['username'];

		$InsertQuery = "INSERT INTO reviews (parkID, userID, review, rating, username)
		VALUES(:parkID, :userID, :review, :rating, :username)";
		$insertStmt = $database->prepare($InsertQuery);

		$insertStmt->bindParam(':parkID', $parkID);
		// $insertStmt->bindParam(':datePosted', $postedDate);
		$insertStmt->bindParam(':userID', $userID);
		$insertStmt->bindParam(':review', $review);
		$insertStmt->bindParam(':rating', $rtng);
		$insertStmt->bindParam(':username', $username);

		$insertStmt->execute();
	} catch (Exception $e) {
	echo "exceptional";
	echo $e->getMessage();
	}
}
try {
	global $database;
	$parkID = $_GET['id'];
	$query = "SELECT * from items
	LEFT JOIN reviews ON items.id = reviews.parkID
	LEFT JOIN members ON reviews.userID = members.userID
	WHERE id = ".$parkID;
	$parkIDstmt = $database->prepare($query);
	$parkIDstmt->execute();


	// Loop through each review
	foreach($parkIDstmt as $review){
		$reviews = $review['review'];
		if(empty($reviews)){
			echo '<p>There are no reviews for this park yet</p>';
			echo "<p>But you can add a review now!</p>";
		} else {
		// Change date into an acceptable format
		$dateText = date("h:ia jS M Y", strtotime($review['datePosted']));

		echo "<div>
				<p><p>
					<b><span>
						<span>".$review['rating']."</span> out of
						<span>5</span> stars
					</span></b> -\"<i><span>".$review['review']."</span></i>\" -
					<b><span>".$review['username']."</span></b> at ".$dateText."<br><br>
				</p></p>
			</div>";
	}
}
} catch (Exception $e) {
	echo "exceptionallmaoooo";
	echo $e->getMessage();
}
