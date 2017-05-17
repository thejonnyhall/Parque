<html>
    <head>
        <link href="./public/css/assignmentcss.css" rel="stylesheet" type="text/css"/>
        <title>Login</title>
    </head>


    <body>
        <div id="wrapper">
            <div id="middlebit">
                <?php require './includes/partials/titlemenu.inc'; ?>
                <?php

                $link = mysqli_connect("localhost", "root", "root", "parque");

                // Check connection
                if($link === false){
                    die("ERROR: Could not connect. " . mysqli_connect_error());
                }

                // Attempt insert query execution
                $sql = "INSERT INTO parque.members (firstName, lastName) VALUES ('Oswald', 'Doring')";
                if(mysqli_query($link, $sql)){
                    echo "Records inserted successfully.";
                } else{
                    echo "ERROR: Could not able to execute $sql. " . mysqli_error($link);
                }

                // Close connection
                mysqli_close($link);
                ?>

                <div class="content">
                    <h1>Login Here</h1>
                    <br>
                    <div class="loginform">
                        <form method="post" action="processData.php">
                            <p>Username<br><br><input type="text" name="firstname" size="25" maxlength="30" required="required"/> </p>
                            <p>Password<br><br><input type="password" name="password" size="25" maxlength="50" required="required"/> </p>
                            <button type="submit">Login</button>
                        </form>
                        <p>Don't have an account? </p><a href="register.html">Register here</a>
                    </div>
                    <br><br>
                </div>


            </div>
        </div>
    </body>
    <footer>
        <div id="footer">
            Website made by Jonny Hall 51% and Oswald Doring 49% Titled: "Give me a 7 pls" <br>Jozwald 2017
        </div>
    </footer>
</html>
