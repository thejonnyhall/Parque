// function makeRed(){
//     var x = document.getElementById("middlebit");
//     x.style.color = "red";
// }
//
// function initMap() {
//   var map = new google.maps.Map(document.getElementById('map'), {
//     center: {lat: -34.397, lng: 150.644},
//     zoom: 6
//   });
//   var infoWindow = new google.maps.InfoWindow({map: map});
//
//   // Try HTML5 geolocation.
//   if (navigator.geolocation) {
//     navigator.geolocation.getCurrentPosition(function(position) {
//       var pos = {
//         lat: position.coords.latitude,
//         lng: position.coords.longitude
//       };
//
//       infoWindow.setPosition(pos);
//       infoWindow.setContent('Location found.');
//       map.setCenter(pos);
//     }, function() {
//       handleLocationError(true, infoWindow, map.getCenter());
//     });
//   } else {
//     // Browser doesn't support Geolocation
//     handleLocationError(false, infoWindow, map.getCenter());
//   }
// }
//
// function handleLocationError(browserHasGeolocation, infoWindow, pos) {
//   infoWindow.setPosition(pos);
//   infoWindow.setContent(browserHasGeolocation ?
//                         'Error: The Geolocation service failed.' :
//                         'Error: Your browser doesn\'t support geolocation.');
// }
//
//
// async defer {
// src="https://maps.googleapis.com/maps/api/js?key=AIzaSyAcmvmzRY3PXgFm5scQnahQ6aTJOO_kMTU&callback=initMap">
// }

// function redirect(){
//     if (true) {
//         window.location.href = 'result.html';
//     } else {
//         return false;
//     }
// }

// function validate(){
//     checkSuburb();
// }
//
// function checkSuburb(){
//     if(document.getElementById("suburb").value == " ") {
//         document.getElementById("suburbMissing").style.visibility = "visible";
//         return false;
//     } else {
//         return true;
//     }
// }
//
// function suburbVisible(){
//     document.getElementById("suburbMissing").style.visibility = "hidden";
// }

function validate(){
    checkFirstName();
    checkLastName();
    checkEmail();
    checkemail();
    checkDOB();
    checkPostcode();
    checkpassword();
    checkConfirmpassword();
    checkTerms();
    return true;
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
function checkemail(){
    if(document.getElementById("email").value == "") {
        document.getElementById("emailMissing").style.visibility = "visible";
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
function checkpassword(){
    if(document.getElementById("password").value == "") {
        document.getElementById("passwordMissing").style.visibility = "visible";
        return false;
    } else {
        return true;
    }
}
function checkConfirmpassword(){
    if(document.getElementById("confirmpassword").value == "") {
        document.getElementById("confirmpasswordMissing").style.visibility = "visible";
        return false;
    } else {
        return true;
    }
}
function checkTerms(){
    if(document.getElementById("terms").value == "") {
        document.getElementById("termsMissing").style.visibility = "visible";
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
function emailVisible(){
    document.getElementById("emailMissing").style.visibility = "hidden";
}
function dobVisible(){
    document.getElementById("dobMissing").style.visibility = "hidden";
}
function postcodeVisible(){
    document.getElementById("postcodeMissing").style.visibility = "hidden";
}
function passwordVisible(){
    document.getElementById("passwordMissing").style.visibility = "hidden";
}
function confirmpasswordVisible(){
    document.getElementById("confirmpasswordMissing").style.visibility = "hidden";
}
function termsVisible(){
    document.getElementById("termsMissing").style.visibility = "hidden";
}

function registerForm(){
    if (true) {
        window.location.href = 'index.html';
    } else {
        window.location.href = 'register.html';
    }
}

function getSearchResults(){
    // Get each of the inputs for search criteria.
    var search = {name: '', suburb: '', rating: 0, location: {lat: 0, lon: 0, radius: 0}};
    search.name = document.getElementById('name').value;
    search.suburb = document.getElementById('suburb').value;
    search.rating = document.getElementById('rating').value;
    search.location.radius = document.getElementById('location').value;
}

function initMap() {
  var myLatLng = {lat: <? echo "$lat"; ?>, lng: <? echo "$lon"; ?>};

  var map = new google.maps.Map(document.getElementById('map'), {
    zoom: 14,
    center: myLatLng
  });

  var marker = new google.maps.Marker({
    position: myLatLng,
    map: map,
    title: 'Hello World!'
  });
}
async defer
src="https://maps.googleapis.com/maps/api/js?key=AIzaSyCubfs3n_PUPa8RoYLEtwmC0BvN_yIoG80&callback=initMap">
