<ul id="menubuttons">
    <li><a href="index.php">Home</a></li>
    <li><a href="search.php">Search a Park</a></li>
    <li><a href="register.php">Register</a></li>

    <?
    if($_SESSION){
        echo "<li><a href='logout.php'>Logout</a></li>";
    } else {
        echo "<li><a href='login.php'>Login</a></li>";
    }
    ?>
</ul>
