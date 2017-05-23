<?php
//if the button is clicked
if (isset($_POST['submit'])) {
    global $database;
    try {
        // Get what the user types in, stores them in variables
        $email = $_POST['email'];
        $password = $_POST['password'];

        // Validate user input
        validate_email($email);
        $password =  sha1($password);

        // Query time lmao kms
        // Protects from sql injection
        $stmt = $database->prepare("SELECT userID, firstName, email, password FROM members WHERE email = :email");

        $stmt->execute(array(
				':email' => $email
				));

        $data = $stmt->fetch(PDO::FETCH_ASSOC);
        if($data == false){
				echo "wrong username man";;
			} else {
				if($password == $data['password']) {
                    $_SESSION['id'] = $data['userID'];
					$_SESSION['name'] = $data['firstName'];
					$_SESSION['email'] = $data['email'];
					$_SESSION['password'] = $data['password'];

					echo "Sucessfully Logged in, redirecting now";

                    ?> <script> document.location = "http://localhost/assignment/index.php"; </script> <?
                    sleep(2);
                     exit;
				} else {
					echo "password wrong fam";
			}
        }
    } catch (Exception $e) {
            echo "Try Catch exception";
        }
    }
?>
