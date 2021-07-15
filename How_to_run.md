**Steps to run the code on your device**
--------------------------------------
### 1. Download the dataset
You first need to download the ROOT data file: [16O_C2H4_200_01.root](https://github.com/rotolanna/Software_and_Computing_Project.git).

Then, move the ROOT File into your code folder, in which there is the Analysis_input. This latter contains the beam features (mass number, charge, kinetic energy in GeV) and 
the name of the ROOT file. 

Open Analysis_input, as notes, and check the ROOT data file name is right.

### 2. Download the file
You need to download the file from the repository of GitHub.

Click on the button "Clone or download" and than click on "Download ZIP".

### 3. Extract the program from the download file
You need a software like "Winrar" to extract the files from the ZIP document.

Once you've done this, you need to search for the file "Project_01", into the "Project" folder.

Extract the whole Project_01 on your Desktop and add the ROOT data file 16O_C2H4_200_01.root in this folder.

### 4. Run the code on your computer
To run the code you need first to download and install [Ubuntu](https://phoenixnap.com/kb/how-to-install-ubuntu-18-04). I used the [Ubuntu bash](https://altis.com.au/installing-ubuntu-bash-for-windows-10/) (18.04 version) on OS: Windows 10.

Now, install the [Cmake](https://cmake.org/install/) for Linux system and [GNU Make Compiler](https://www.howtoinstall.me/ubuntu/18-04/make/).

Then, install, through the terminal, the ROOT program from the [site ROOT Cern](https://root.cern/). ROOT uses the CMake cross-platform build-generator tool as the primary build system.
CMake generates the files needed by your build tool (GNU make, Visual Studio, etc) for building ROOT.

Once you've installed them, you've to move into your Project_01 folder, writing the right path on the Ubuntu bash.

If you use the bash on another OS, you first move into your ROOT folder and tip this command `. bin/thisroot.sh` and click the enter key.

Then you've to move into your Project_01 folder, writing the right path on the Ubuntu bash. Check the code with the *make compiler* : 

`make clean` 

`make`

Now, run the Analysis.cpp file : 

`./Analysis`
                                                                                                                                     
In order to see the output.root file, write the command `root`. Then `new TBrowser` and click the enter key. 

Once you've opened the TBrowser, you've to find the *out.root* file among the ROOT folders. Click on it and it will be divided in two folders, called *Generation* and *Reconstruction*.
Both contain some plots/results.






