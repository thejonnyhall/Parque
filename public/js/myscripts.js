/* <-------    Validation Functions for registration    -------> */
function validate(){
    if (checkFirstName() & checkLastName() & checkEmail() & checkPassword() &
    checkDOB() & checkPostcode()){
        return true;
    }
    return false;
}

function checkFirstName(){
    if(document.getElementById("firstname").value == "") {
        document.getElementById("firstNameMissing").style.visibility = "visible";
        return false;
    } else {
        return true;
    }
}
function checkLastName(){
    if(document.getElementById("lastname").value == "") {
        document.getElementById("lastNameMissing").style.visibility = "visible";
        return false;
    } else {
        return true;
    }
}
function checkEmail(){
    if(document.getElementById("email").value == "") {
        document.getElementById("emailMissing").style.visibility = "visible";
        return false;
    } else {
        return true;
    }
}
function checkPassword(){
    if(document.getElementById("password").value == "") {
        document.getElementById("passwordMissing").style.visibility = "visible";
        return false;
    } else {
        return true;
    }
}
function checkDOB(){
    if(document.getElementById("dob").value == "") {
        document.getElementById("dobMissing").style.visibility = "visible";
        return false;
    } else {
        return true;
    }
}
function checkPostcode(){
    if(document.getElementById("postcode").value == "") {
        document.getElementById("postcodeMissing").style.visibility = "visible";
        return false;
    } else {
        return true;
    }
}

function firstNameVisible(){
    document.getElementById("firstNameMissing").style.visibility = "hidden";
}
function lastNameVisible(){
    document.getElementById("lastNameMissing").style.visibility = "hidden";
}
function emailVisible(){
    document.getElementById("emailMissing").style.visibility = "hidden";
}
function passwordVisible(){
    document.getElementById("passwordMissing").style.visibility = "hidden";
}
function dobVisible(){
    document.getElementById("dobMissing").style.visibility = "hidden";
}
function postcodeVisible(){
    document.getElementById("postcodeMissing").style.visibility = "hidden";
}


/* <--------    Map Functions for Searching    ---------> */

function initMap() {
	// Create a location array for any location (doesn't matter where)
	var myLatLng = {lat: -27.467401, lng: 153.025101};

	// Initialise map
	map = new google.maps.Map(document.getElementById('map'), {
	  zoom: 10,
	  center: myLatLng,
	  mapTypeId: google.maps.MapTypeId.HYBRID
	});

	// Add bounds to map
	bounds = new google.maps.LatLngBounds();
}

function addMarkerToMap(latitude,longitude,name,id,rating,suburb){
	// Create a location array
	var myLatLng = {lat: parseFloat(latitude), lng: parseFloat(longitude)};

	// Create label for the marker
	var contentString = "<h3>"+name+"</a></h3>"+
						"<b>Suburb: </>"+suburb+"<br/>"+
						"<b>Rating: </>"+rating+"<br/>";

	// // Use label to create an info window in marker
	// var infowindow = new google.maps.InfoWindow({
	// 	content: contentString
	// });

	// Create the marker
	var marker = new google.maps.Marker({
		position: myLatLng,
		map: map,
	});

	// add a listener to open the info window when clicked
	marker.addListener('click', function() {
		infowindow.open(map, marker);
	});

	// Extend the bound of the map to include marker
	loc = new google.maps.LatLng(marker.position.lat(), marker.position.lng());
	bounds.extend(loc);

	// Fit and center the map to the bounds
	map.fitBounds(bounds);
	map.panToBounds(bounds);
}
