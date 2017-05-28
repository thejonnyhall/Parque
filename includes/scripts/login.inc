<?
if(isset($_POST['submit'])){
    global $errors;
    try {
        $email = $_POST['email'];
        $password = $_POST['password'];

        $results = get_salt($email);

        $password = sha1($password . $results['salt']);

        $loggedIn = login($email, $password);
        if ($loggedIn['userID'] > 0){
            $_SESSION['loggedIn'] = true;
            $_SESSION['firstName'] = $loggedIn['firstName'];

            echo "Sucessfully Logged in ";
            print_r($loggedIn['firstName']);
            sleep(2);
            ?>
            <script> document.location = "http://localhost/assignment/index.php"; </script>
            <?
        } else {
            print_r($errors);
        }

    } catch(PDOException $e){
        echo "exceptional";
        die ($e->getMessage());
    }

}
?>
