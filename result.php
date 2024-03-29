<? require "./includes/partials/header.inc" ?>
<? require "./includes/partials/navigation.inc" ?>
<!--	These variables are global variables used for the map-->
	<script type="text/javascript">
        var map;
        var bounds;
    </script>

	<script src="https://developers.google.com/maps/documentation/javascript/examples/markerclusterer/markerclusterer.js">
	</script>


                <h1>Results of your park search</h1><br>
                <div class="map" id="map"></div>
				<script	src="https://maps.googleapis.com/maps/api/js?key=AIzaSyDFdqpcCyNQSmIGuIOZyNKOfKjvqp0Vv3Q&callback=initMap">
				</script>
                <br>
                <div class="resulttable">
                    <table id="resulttable" border="3" >
                        <colgroup span="5"></colgroup>
                        <thead>
                            <tr>
                                <th>Park Name</th>
                                <th>Suburb</th>
                                <th>Rating</th>
                            </tr>
                        </thead>
                        <tbody>
							<? require "./includes/scripts/results.inc"; ?>
							<? require "./includes/scripts/location.inc"; ?>
                        </tbody>
                    </table>
                </div>
            </div>
        </div>

<? require "./includes/partials/footer.inc" ?>
