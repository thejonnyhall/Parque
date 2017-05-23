<? require "./includes/partials/header.inc" ?>
<? require "./includes/partials/navigation.inc" ?>


                <h1>Results of your park search</h1><br>
                <div class="map">
                    <img src="./public//css/images/testmap.png" alt="testmap" width="546" align="center">
                </div>
                <br><br>

                <div class="resulttable">
                    <table id="resulttable" border="3" >
                        <colgroup span="5"></colgroup>
                        <thead>
                            <tr>
                                <th>Park Name</th>
                                <th>Suburb</th>
                                <th>Grid Coords</th>
                            </tr>
                        </thead>
                        <tbody>
                            <? require "./includes/scripts/search.inc"; ?>
                        </tbody>
                    </table>
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
