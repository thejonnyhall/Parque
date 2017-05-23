<?
    // dbconfig params
    require_once "./config/dbconfig.inc";
    // Database connection
    require_once "./lib/database.inc";
    require_once "./includes/functions.inc"

?>
<html>
    <head>
        <link href="./public/css/heck.css" rel="stylesheet" />
        <script src="./public/js/myscripts.js"></script>
    </head>
    <body>
        <div id="wrapper">
            <div id="middlebit">
                <div id="header">
                    <br>
                    <a href="index.php"><img src="./public/css/images/parque2.png" alt="logo" width="500" align="center"></a>
                    <br><br>
                    <?
                    if(!empty($_SESSION['id'])) {
                        echo "Welcome " .$_SESSION['name'];
                    } else {
                        echo "";
                    } ?>
                </div>
