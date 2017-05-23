<?
    if (isset($_POST['submit'])) {
        global $database;
        try {
            // Collect input values
            $firstname = $_POST['firstName'];
            $lastname = $_POST['lastName'];
            $email = $_POST['email'];
            $password = $_POST['password'];
            // Validate user input
            validate_first_name($firstname);
            validate_last_name($lastname);
            validate_email($email);
            // Count if there are any errors found
            if (count($errors) === 0) {
                $password =  sha1($password);
                // Create and prepare query
                $query = "INSERT INTO members (firstName, lastName, email, password)
                VALUES (:firstName, :lastName, :email, :password)";
                // Prepare the statement to prevent SQL injections
                $stmt = $database->prepare($query);
                // Bind parameters
                $stmt->bindParam(':firstName', $firstname);
                $stmt->bindParam(':lastName', $lastname);
                $stmt->bindParam(':email', $email);
                $stmt->bindParam(':password', ($password));
                // Execute the query
                $stmt->execute();
                if ($stmt->rowCount() > 0) {
                    // Get newly created account ID
                    $userID = $database->lastInsertId();
                    // Redirect to index.php
                    echo "<br>";
                    echo "User Created";
                    ?>
                    <script> document.location = "http://localhost/assignment/index.php"; </script>
                    <?
                }
            } else {
                print_r($errors);
            }
        } catch (PDOException $e) {
            die($e->getMessage());
        }
    }
?>
