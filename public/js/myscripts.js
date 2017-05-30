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
var map;
var bounds;
var markers = new Array();
function initMap() {
	// Create a location array for any location (doesn't matter where)
	var myLatLng = {lat: -27.467401, lng: 153.025101};

	// Initialise map
	map = new google.maps.Map(document.getElementById('map'), {
	  zoom: 10,
	  center: myLatLng,
	  mapTypeId: google.maps.MapTypeId.ROADMAP
	});

	// Add bounds to map
	bounds = new google.maps.LatLngBounds();
}

function displayMarkers(results) {

    var markers = new Array();
    results.forEach(function(park){
        var myLatLng = {lat: Number(park['latitude']),lng: Number(park['longitude'])};
        // Create label for the marker
    	var contentString = "<h3><a href='itemResult.php?id="+park['id']+"'>"+park['name']+"</a></h3>"+
    						"<b>Suburb: </>"+park['suburb']+"<br/>"+
    						"<b>Rating: </>"+park['avgRating']+"<br/>";

    	// // Use label to create an info window in marker
    	var infowindow = new google.maps.InfoWindow({
    		content: contentString
    	});
        var marker = new google.maps.Marker({
            position: myLatLng,
    		map: map
        });
        marker.addListener('click', function() {
    		infowindow.open(map, marker);
    	});
        bounds.extend(myLatLng);
        map.fitBounds(bounds);
        markers.push(marker);
    });
    var markerCluster = new MarkerClusterer(map, markers,
        {imagePath: 'https://developers.google.com/maps/documentation/javascript/examples/markerclusterer/m'});

}

function addTheBigMarker(position) {
    var myLatLng = {lat: Number(position['lat']),lng: Number(position['lon'])};
    var marker = new google.maps.Marker({
        position: myLatLng,
        icon: "images/people35.png",
        map: map
    });
}

function showPosition(position){
    window.location = 'result.php?lat='+position.coords.latitude+"&lng="+position.coords.longitude;

}

function searchByLocation(){
    if (navigator.geolocation) {
        navigator.geolocation.getCurrentPosition(showPosition);
    } else {
        x.innerHTML = "Geolocation is not supported by this browser.";
    }
}
