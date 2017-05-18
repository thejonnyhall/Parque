<?php
    //if the button is clicked
    if (isset($_POST['submit'])) {
        try {
            $stmt = $pdo->prepare('SELECT password, salt FROM members where email = :email');
            echo "heck";


        } catch (Exception $e) {
                echo "oswaldsucks";
            }
        }
            // Protects from sql injection
    //
    //
    //         // Binds the paramaters
    //         $stmt->bindParam("email", $email);
    //
    //         // //Executes to the database
    //         $stmt->execute();
    //         echo "lmao renz";
    //         //
    //         //If something is there, fetch all
    //         if ($stmt->rowCount() > 0) {
    //             $results = $stmt->fetchALl();
    //
    //             // Comparing passwords from user entered password, to password in database
    //             $passwordCom = sha1($password . $results['salt']);
    //
    //             if ($passwordCom === $password) {
    //                 echo "it works";
    //             } else {
    //                 error_message($errors, "Email and Password combination is incorrect");
    //                 return false;
    //             }
    //         }
    //
    //     } catch (Exception $e) {
    //         echo "oswaldsucks";
    //     }
    // }

        // get post params
        //
        // get salt, password where email = :email
        //
        // encrypt passowrds from params (not db)
        //
        // compare encrypt password to password from db
        //
        // if true login, else error

    //}

    // if($user->is_loggedin()!="") {
    //     $user->redirect('home.php');
    // }

    // if(isset($_POST['submit'])) {
    //     $uname = $_POST['email'];
    //     $upass = $_POST['password'];

    // if($user->login($uname,$upass)) {
    //     $user->redirect('index.php');
    // } else {
    //     $error = "Wrong Details !";
    //     }
    //}
    ?>
