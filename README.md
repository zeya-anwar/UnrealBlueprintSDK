Unreal4.9 Blueprint SDK-Collection for PlayFab README
========


1. Overview:
----
Unreal 4.9 Blueprint SDKs for PlayFab - BETA

The Unreal Blueprint SDK-Collection includes three separate Unreal 4.9 plugins.  You should only install 1 of these plugins in any Unreal project.

* Unreal Client SDK for distribution to End-Users
* Unreal Server SDK for secure machines running sensitive logic
* Unreal Combo SDK for demoing, testing, and special-case circumstances - Typical users will not use this for production code


2. Prerequisites:
----
* Users should be very familiar with the topics covered in our [getting started guide](https://playfab.com/docs/getting-started-with-playfab/).

To connect to the PlayFab service, your machine must be running TLS v1.2 or better.
* For Windows, this means Windows 7 and above
* [Official Microsoft Documentation](https://msdn.microsoft.com/en-us/library/windows/desktop/aa380516%28v=vs.85%29.aspx)
* [Support for SSL/TLS protocols on Windows](http://blogs.msdn.com/b/kaushal/archive/2011/10/02/support-for-ssl-tls-protocols-on-windows.aspx)


3. Setup:
----
For building the game client, distributed to the End-User, you must only use the PlayFabClientSDK.

A game server is not required for all games, however many online games require online server architecture.  PlayFab also does not require you to use the same SDK for client and server.  If your game-server is a separate stand-alone console application, it is possible to use the [C++ WindowsSDK](https://github.com/PlayFab/WindowsSDK).  If your game-server requires an Unreal environment, you can also use the PlayFabServerSDK provided with in the Unreal SDK-Collection.

To implement both client and server in Unreal, you must create two separate projects, and install each plugin separately.


4. Installation:
----
The following instructions apply to each of the three SDKs provided in the Unreal SDK-Collection.

Assumptions

* Windows operating system
* [Microsoft Visual Studio](https://www.visualstudio.com/en-us/products/visual-studio-community-vs.aspx) already installed
* [Unreal Engine](https://www.unrealengine.com/dashboard) already installed

A new project can be built directly from the example project included with each SDK:

* Extract the Unreal SDK package to {UnrealPackageLocation}
* Navigate to {UnrealPackageLocation}/PlayFabClientSDK/ExampleProject
* Right click on ExampleProject.uproject, and "Generate Visual Studio project files" - This process may take several minutes
* Once finished, open {UnrealPackageLocation}/PlayFabClientSDK/ExampleProject/ExampleProject.sln in Visual Studio
* In Visual Studio, "Rebuild Solution" - This process may take several minutes
* You should now be able to create blueprints that utilize PlayFab API calls

Existing Projects:
* Extract the Unreal SDK package to {UnrealPackageLocation}
* Navigate to {UnrealPackageLocation}/PlayFabClientSDK\PluginFiles
* Copy the PlayFab folder into the "Plugins" directory in your existing Unreal project (If the "Plugins" folder does not exist, create it)
* Right click on ExampleProject.uproject, and "Generate Visual Studio project files" - This process may take several minutes
* Once finished, open your *.sln project file with Visual Studio
* In Visual Studio, "Rebuild Solution" - This process may take several minutes
* You should now be able to create blueprints that utilize PlayFab API calls


5. Blueprint Tutorial:
----
The plugin is fairly simple to use. The main things you need to learn are; how to use the provided JSON objects, how to wire up the nodes, and realize that it is extremely simple!

Below are the steps to add an API call node, and manipulate the response JSON object. We will make a simple login with email function that will print out the response JSON object to the screen.

* Open the Unreal editor by double clicking on the project file.
* Got to the top bar and select "Blueprints" then "Open Level Blueprint" from the drop down menu.
* ![Open Level Blueprint](OpenLevelBP.png)
* Right click on an empty spot and add an "Add Custom Event Node".
* Name it something you will remember to be called from the console manager.
* Now add two string variables named "Email" and "Password" to the custom event.
* Right click again and search for the "Login With Email Address" node located in "Play Fab/Client/Authentication".
* You can also type "login" in the search field to find it quicker.
* Now wire up the "Email" on the event to the "Email" on the api node. Do the same for the "Password".
* The response on the node is a JSON object that can be manipulated using the provided JSON functions located in "Play Fab/Json".
* Drag off from the response node and search for "Encode Json"
* Now wire the "Encode Json" return up to a "Print String" node. Below is an image of the complete system.
* ![Open Level Blueprint](Login.png)
* Now run the project and in the play in editor window hit the tilde ~ key. This will bring up the console manager.
* Now type "ce TestLogin "email@email.com" password"
* Notice you add quotes to email but not to password.
* Once you hit enter you should get the response printed out on the screen.


6. Troubleshooting:
----
If you experience this error:
Plugin 'PlayFab' failed to load because module 'PlayFab' could not be found.  Please ensure the plugin is properly installed, otherwise consider disabling the plugin for this project.

Your Unreal project is not set up to be a C++ project.  Here is a tutorial that will help fix this problem.
http://idkudk.blogspot.com/2015/02/how-to-get-plugins-to-package-correctly.html


General troubleshooting:

For a complete list of available APIs, check out the [online documentation](http://api.playfab.com/Documentation/).

#### Contact Us
We love to hear from our developer community!
Do you have ideas on how we can make our products and services better?

Our Developer Success Team can assist with answering any questions as well as process any feedback you have about PlayFab services.

[Forums, Support and Knowledge Base](https://community.playfab.com/hc/en-us)


7. Acknowledgements
----
The PlayFab UnrealBlueprintSDK and the Blueprint Tutorial in this document were built by [Joshua Lyons](https://github.com/JLyons1985), and submitted to PlayFab October, 2015


8. Copyright and Licensing Information:
----
  Apache License --
  Version 2.0, January 2004
  http://www.apache.org/licenses/

  Full details available within the LICENSE file.

