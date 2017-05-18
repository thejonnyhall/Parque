<? require_once './includes/partials/header.inc'; ?>
<? require_once './includes/partials/navigation.inc'; ?>
<? require_once './includes/scripts/login.inc'; ?>


<div class="content">
    <h1>Login Here</h1>
    <br>
    <div class="loginform">
        <form method="post" action="login.php">
            <p>email<br><br>
                <input type="email" name="email" size="25" maxlength="30" /> </p>
            <p>Password<br><br>
                <input type="password" name="password" size="25" maxlength="50" /> </p>
            <input type="submit" name="submit" value="Login" />
        </form>
        <p>Don't have an account? </p><a href="register.php">Register here</a>
    </div>
    <br><br>
</div>


<? require "./includes/partials/footer.inc"; ?>
