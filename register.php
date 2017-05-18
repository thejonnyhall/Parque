<? require "./includes/partials/header.inc"; ?>
<? require "./includes/partials/navigation.inc"; ?>
<? require "./includes/scripts/register.inc"; ?>

<title>Register</title>
    <div class="content">
        <h1>Register</h1>
        <p9>Fields indicated with * are required</p9>

        <form action="register.php" method="post">
            <p>Full Name* <br><input type="text" id="firstname" type="text" name="firstName" value="<? $_POST['firstName'] ?? ''; ?>"
                placeholder="First Name" oninput="firstNameVisible()" />

            <input type="text" id="lastname" name="lastName" size="15" maxlength="30" placeholder="Last Name" oninput="lastNameVisible()" />
                <br>
            <span id="firstNameMissing" class="error-message"> First Name is a required field </span>
            <span id="lastNameMissing" class="error-message"> Last Name is a required field </span>
            </p>

            <p>Email* <br><input type="text" id="email" name="email" size="34" maxlength="50" placeholder="Email" oninput="emailVisible()" />
                <br>
            <span id="emailMissing" class="error-message"> Email is a required field </span>

            <!-- <p>email* <br><input type="text" id="email" name="email" size="34" maxlength="30" placeholder="email" oninput="emailVisible()" />
                <br>
            <span id="emailMissing" class="error-message"> email is a required field </span> -->

            <p>Password* <br><input type="password" id="password" name="password" size="34" maxlength="50" placeholder="Password" oninput="passwordVisible()" />
                <br>
            <span id="passwordMissing" class="error-message"> Password is a required field </span>

            <!-- <p>Date of Birth <br><input type="date" id="dob" name="dob" size="10" oninput="dobVisible()" />
                <br>
            <span id="dobMissing" class="error-message"> Date of Birth is a required field </span>

            <p>Postcode <br><input type="number" id="postcode" name="postcode" size="4" maxlength="4" min="1000" max="9999" placeholder="1111" oninput="postcodeVisible()"/>
                <br>
            <span id="postcodeMissing" class="error-message"> Postcode is a required field </span> -->


            <!-- <p>Confirm Password* <br><input type="password" id="confirmpassword" name="confpassword" size="34" maxlength="50" placeholder="Confirm Password" oninput="confirmPasswordVisible()" />
                <br>
            <span id="confirmPasswordMissing" class="error-message"> Confirm Password is a required field </span>

            <p>Do you accept our Terms and Conditions?*</a> <input type="checkbox" id="terms" name="terms" oninput="termsVisible()" />
                <br>
            <span id="termsMissing" class="error-message"> Terms and Conditions is a required field </span>
                </p></p></p></p></p></p></p> -->
            <input type="submit" name="submit" value="Submit" />
        </form>
    </div>
<?php require "./includes/partials/footer.inc"; ?>
