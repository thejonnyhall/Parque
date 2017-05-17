<html>
    <head>
        <link href="./public/css/assignmentcss.css" rel="stylesheet" type="text/css"/>
        <script type="text/javascript" src="./public/js/myscripts.js"></script>

        <title>Register</title>
    </head>


    <body>
        <div id="wrapper">
            <div id="middlebit">
                <?php require './includes/partials/titlemenu.inc'; ?>

                <div class="content">
                    <h1>Register</h1>
                    <p9>Fields indicated with * are required</p9>
                    <form target="_self" action="javascript:validate()">
                        <p>Full Name* <br><input type="text" id="firstname" name="firstname" size="15" maxlength="30" placeholder="First Name" oninput="firstNameVisible()" />
                        <input type="text" id="lastname" name="lastname" size="15" maxlength="30" placeholder="Last Name" oninput="lastNameVisible()" />
                            <br>
                        <span id="firstNameMissing" class="error-message"> First Name is a required field </span>
                        <span id="lastNameMissing" class="error-message"> Last Name is a required field </span>
                        </p>

                        <p>Email* <br><input type="text" id="email" name="email" size="34" maxlength="50" placeholder="Email" oninput="emailVisible()" />
                            <br>
                        <span id="emailMissing" class="error-message"> Email is a required field </span>

                        <p>Username* <br><input type="text" id="username" name="username" size="34" maxlength="30" placeholder="Username" oninput="usernameVisible()" />
                            <br>
                        <span id="usernameMissing" class="error-message"> Username is a required field </span>

                        <p>Date of Birth <br><input type="date" id="dob" name="dob" size="10" oninput="dobVisible()" />
                            <br>
                        <span id="dobMissing" class="error-message"> Date of Birth is a required field </span>

                        <p>Postcode <br><input type="number" id="postcode" name="postcode" size="4" maxlength="4" min="1000" max="9999" placeholder="1111" oninput="postcodeVisible()"/>
                            <br>
                        <span id="postcodeMissing" class="error-message"> Postcode is a required field </span>

                        <p>Password* <br><input type="password" id="password" name="password" size="34" maxlength="50" placeholder="Password" oninput="passwordVisible()" />
                            <br>
                        <span id="passwordMissing" class="error-message"> Password is a required field </span>

                        <p>Confirm Password* <br><input type="password" id="confirmpassword" name="confpassword" size="34" maxlength="50" placeholder="Confirm Password" oninput="confirmPasswordVisible()" />
                            <br>
                        <span id="confirmPasswordMissing" class="error-message"> Confirm Password is a required field </span>

                        <p>Do you accept our Terms and Conditions?*</a> <input type="checkbox" id="terms" name="terms" oninput="termsVisible()" />
                            <br>
                        <span id="termsMissing" class="error-message"> Terms and Conditions is a required field </span>
                            </p></p></p></p></p></p></p>
                        <input type="submit" value="Submit">
                    </form>
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
