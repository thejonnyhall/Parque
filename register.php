<? require "./includes/partials/header.inc"; ?>
<? require "./includes/partials/navigation.inc"; ?>
<? require "./includes/scripts/register.inc"; ?>

<title>Register</title>
    <div class="content">
        <h1>Register</h1>
        <p9>Fields indicated with * are required</p9>

        <form action="register.php" method="post" onsubmit="return validate()">
            <p>Full Name* <br><input type="text" id="firstname" type="text" name="firstName" value="<?= $_POST['firstName'] ?? ''; ?>" placeholder="First Name" oninput="firstNameVisible()" />

            <input type="text" id="lastname" name="lastName" size="15" maxlength="30" value="<?= $_POST['lastName'] ?? ''; ?>" placeholder="Last Name" oninput="lastNameVisible()" />
                <br>
            <span id="firstNameMissing" class="error-message"> First Name is a required field </span>
            <span id="lastNameMissing" class="error-message"> Last Name is a required field </span>
            </p>

            <p>Email* <br><input type="email" id="email" name="email" value="<?= $_POST['email'] ?? ''; ?>" size="34" maxlength="50" placeholder="Email"  oninput="emailVisible()" />
                <br>
            <span id="emailMissing" class="error-message"> Email is a required field </span>

            <p>password* <br><input type="password" id="password" name="password" size="34" maxlength="50" placeholder="password" oninput="passwordVisible()" />
                <br>
            <span id="passwordMissing" class="error-message"> password is a required field </span>

            <p>Date of Birth <br><input type="text" id="dob" name="dob" value="<?= $_POST['dob'] ?? ''; ?>" size="10" oninput="dobVisible()" />
                <br>
            <span id="dobMissing" class="error-message"> Date of Birth is a required field </span>

            <p>Postcode <br><input type="number" id="postcode" name="postcode" size="4" value="<?= $_POST['postcode'] ?? ''; ?>" maxlength="4" min="1000" max="9999" placeholder="1111" oninput="postcodeVisible()"/>
                <br>
            <span id="postcodeMissing" class="error-message"> Postcode is a required field </span>

            <p>Would you like to receive annoying emails about parks weekly?<br><input type="radio" id="radio" name="radio" value="<?= $_POST['radio'] ?? ''; ?>" oninput="radioVisible()" />
                <br>

                </p></p></p></p></p></p></p>
            <input type="submit" name="submit" value="Submit" />
        </form>
    </div>
<?php require "./includes/partials/footer.inc"; ?>
