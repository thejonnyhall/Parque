<ul id="menubuttons">
    <li><a href="index.php">Home</a></li>
    <li><a href="search.php">Search a Park</a></li>
    <li><a href="register.php">Register</a></li>
    <li><a href="login.php">Login</a></li>
    <?
    if(!empty($_SESSION['id'])) {
        ?> <li><a href="logout.php">Logout</a></li> <?
    } else {
        echo "";
    }
    ?>
</ul>
