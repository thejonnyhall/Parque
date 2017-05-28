<?
    if (isset($_POST['submit'])) {
        global $errors;
        global $database;
        try {
            // Collect input values
            $firstname = $_POST['firstName'];
            $lastname = $_POST['lastName'];
            $email = $_POST['email'];
            $password = $_POST['password'];
            $dob = $_POST['dob'];
            $postcode = $_POST['postcode'];
            // Validate user input
            validate_first_name($firstname);
            validate_last_name($lastname);
            validate_email($email);
            // Count if there are any errors found
            if (count($errors) === 0) {

                $saltHash = md5(uniqid());
                $salt = substr($saltHash, 0, 20);

                // Concat salt to password and hash using sha1
                $password =  sha1($password . $salt);

                // Create and prepare query
                $query = "INSERT INTO members (firstName, lastName, email, password, salt, dob, postcode)
                VALUES (:firstName, :lastName, :email, :password, :salt, :dob, :postcode)";
                // Prepare the statement to prevent SQL injections
                $stmt = $database->prepare($query);
                // Bind parameters
                $stmt->bindParam(':firstName', $firstname);
                $stmt->bindParam(':lastName', $lastname);
                $stmt->bindParam(':email', $email);
                $stmt->bindParam(':password', ($password));
                $stmt->bindParam(':salt', $salt);
                $stmt->bindParam(':dob', $dob);
                $stmt->bindParam(':postcode', $postcode);
                // Execute the query
                $stmt->execute();
                if ($stmt->rowCount() > 0) {
                    // Get newly created account ID
                    $userID = $database->lastInsertId();
                    // Redirect to index.php
                    echo "<br>";
                    echo "User Created";
                    ?> <script> document.location = "http://localhost/assignment/index.php"; </script> <?
                }
            } else {
                print_r($errors);
            }
        } catch (PDOException $e) {
            die($e->getMessage());
        }
    }
?>
