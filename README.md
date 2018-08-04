# POC for Google Maps
Google Maps POC outlines the basic features of Google Maps through
the Python client library for Maps Web Services. These examples
focus on potentially useful APIs for retrieving place data,
including Geocoding API, Distance Matrix API, and
Places API.

## Setup
Follow the steps below to get started with using these examples:

* First, clone the repository below:
```
https://github.com/odada2/gmap.git
```

## Dependency Management
* Navigate to the cloned repository and install the required dependencies using:
```
pip3 install -r requirements.txt
```

## Google Places API

### Installation
Install Google Places API using the command below:
* pip install python-google-places

### Get API Key
The Google Maps APIs also require an API Key. To obtain a key to
use for these examples:
1. Visit https://console.developers.google.com/ and login.
2. Create a new project or use an existing project and navigate
to the credentials tab.
3. Once in the dashboard, search for and enable the following APIs:
**Geocoding API, Distance Matrix API, Places API.**
4. Navigate to the credentials tab and create a new API Key
5. Restrict the API Key to the following APIs by clicking on
the APIs tab when editing the key and selecting the enabled APIs.

Refer the link below to obtain API key:
* https://developers.google.com/places/web-service/get-api-key

After setting up an API key, navigate to the cloned repository:
* Create a new file named ```credentials.json``` and paste your key in the format:
```
{
    "api_key": YOUR_API_KEY_HERE
}
```
**_*NOTE: If JSON format is used to store the API key, then the API key also needs to be within double quotes.
The file```credentials.json``` is also included in the .gitignore.
This is to ensure the secrecy of the API Key._**

The examples also require the googlemaps module. In order to
import the module, type the following into the CLI:
```
pip install -U googlemaps
```
The repository should be all setup for use! Now you can enjoy the examples and modify them to your liking!

## Configuration Management
Default application configuration is present in ```config.json```. This file can be updated to change the default arguments for the application.
* Configuration Manager reads ```app.log``` and returns the path to the file.
* Configuration Manager provides methods to load JSON file ```config.json```. It reads the file and returns default values.

## User Input Mechanism
Use the terminal for now.

## Output Mechanism
You can use either the terminal, a CSV file or a JSON file.

## Logger
Application logs which are generated will be stored in ```app.log```.
**_*NOTE:The file```app.log``` is also included in the .gitignore.
This is to ensure the privacy of the user data._**

## Locations
Locations where the search for the 'keywords' is performed are stored in ```locations.py```. It contains a 'country' tag which stores the country of interest, and other tags could be added to store places within that country.

## Place Search
GooglePlaces API allows several different types of searches. We have used Nearby Search.

### Nearby Search (nearby_search)
It allows for a search for places in a specified area. We can expand or refine our research using the attributes to the query, like, 'location', 'keywords', 'type'.

A detailed documentation of the GooglePlaces API can be found in the links below:
* https://developers.google.com/places/web-service/search
* https://developers.google.com/places/web-service/supported_types

### Place Details
Use get_details() method to fetch details of a place.
Details could also be fetched using the 'place_id'. Documentation for the same is given below:
* https://developers.google.com/places/web-service/details

## Google Cloud
Set up a project and download the key stored in a JSON format. This can be done by clicking the 'Set Up A Project' button on the link below:
* https://cloud.google.com/pubsub/docs/quickstart-client-libraries

### Installation
Install the client libraries using the command:
```
pip install --upgrade google-cloud-pubsub
```

### For support on Google Cloud Pub/Sub:
* https://pypi.org/project/google-cloud-pubsub/


### Additional Information
The Google Maps Platform and Web Service provide many tools that
aid in gathering information about different places, such as
searching and getting data through the Places API. The different
APIs also work seamlessly together through using addresses as
search queries or ```place_ids```. This feature also means that
GMaps is also able to interact with other APIs such as Yelp to
extract further information about a location. Extra tools are also included, such
as the ability to calculate distance between two locations with
the Distance Matrix API.

Nonetheless, each API comes with some drawbacks and biases
including the region and viewport biases found in the Geocoding
API. More information can be found in the documentation of each
API. There are also cost considerations as Google API allows 1,000
free requests per 24 hour period on an 'unverified' account and
150,000 free requests per day on a 'verified' account, where verified
means that the account has enabled billing.

### Resources and References
The examples included were derived based on the help found through
Google's documentation, found at the following links:
* Geocoding API: https://developers.google.com/maps/documentation/geocoding/intro
* Distance Matrix API: https://developers.google.com/maps/documentation/distance-matrix/intro
* Places API: https://cloud.google.com/maps-platform/places/
* Client Documentation: https://googlemaps.github.io/google-maps-services-python/docs/
Other References include:
* The MIT License (MIT): https://github.com/slimkrazy/python-google-places
