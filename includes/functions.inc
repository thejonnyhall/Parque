<?php

$errors = [];

function errorMessages(&$errors, $message) {
    array_push($errors, $message);
}

function char_only($str, $message) {
    global $errors;
    if (!preg_match('/^[a-zA-Z ]*$/', $str)) {
        errorMessages($errors, $message);
    }
}

function validate_email($email) {
    global $errors;
    if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
        errorMessages($errors, "Invalid email format");
    }
}
function validate_first_name($name) {
    global $errors;
    $len = strlen($name);
    if ($len < 2 || $len > 30) {
        errorMessages($errors, "First name must have at least 2 characters and less than 30 <br />");
    }

    char_only($name, "First name must not contain numbers");

}

function validate_last_name($name) {
    global $errors;
    $len = strlen($name);
    if ($len < 2 || $len > 30) {
        errorMessages($errors, "Last name must have at least 2 characters and less than 30 <br />");
    }
    char_only($name, "Last name must not contain numbers");
}
function get_salt($email) {
	global $database;
	$query = "SELECT salt FROM members WHERE email = :email";

	$stmt = $database->prepare($query);

	$stmt->bindParam(":email", $email);

	$stmt->execute();

	if($stmt->rowCount() > 0){
		return $stmt->fetch();
	}
}

function login($email, $password) {
	global $database;
	global $errors;
	$query = "SELECT userID, firstName FROM members WHERE email = :email AND password = :password";

	$stmt = $database->prepare($query);

	$stmt->bindParam(":email", $email);
	$stmt->bindParam(":password", $password);

	$stmt->execute();

	if($stmt->rowCount() > 0){
		return $stmt->fetch();
	} else {
		errorMessages($errors, "Email and password combination is incorrect");
		return false;
	}
}

function is_admin($userId) {

	global $database;
	global $errors;
	$query = "SELECT 1 FROM members AS U INNER JOIN user_in_roles AS UIR ON U.id = UIR.user_id WHERE UIR.role_id = 1 AND U.id = :user_id";

	$stmt = $database->prepare($query);

	$stmt->bindParam(":user_id", $user_id);

	$stmt->execute();

	if($stmt->rowCount() > 0){
		$_SESSION['isAdmin'] = true;
	} else {
		$_SESSION['isAdmin'] = false;
	}
}
