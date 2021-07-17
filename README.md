# Software_and_Computing_Project
Project for the Software and Computing exam.


### List of the folders in the repository

[Project](https://github.com/rotolanna/Software_and_Computing_Project/tree/master/Project): this folder contains the whole code of the project and some graphs and informations related to the representation of the final results. 

[Reference Guides](https://github.com/rotolanna/Software_and_Computing_Project/tree/master/Reference%20Guides): this folder contains all the reference guides related to understand how  the FOOT experiment works.

[How-to guides](https://github.com/rotolanna/Software_and_Computing_Project/tree/master/how_to_guides): this folder contains all the guides necessary to execute the program on your device and to reproduce the same simulation with your ROOT data.

NOTE: for each folder there is a proper README.md file that explains in detail what are the documents inside it and what they do.

# Proposal of the repository

In this frame work I will present a short part of my thesis work. The proposed code is a sub-set of a more complex project in the FOOT  environment.

## General Introduction

Particle therapy uses proton or 12C beams for the treatment of deep-seated solid tumors. Due to
the features of energy deposition of charged particles a small amount of dose is released to the
healthy tissue in the beam entrance region, while the maximum of the dose is released to the tumor
at the end of the beam range, in the Bragg peak region. However nuclear interactions between
beam and patient tissues induce fragmentation both of projectile and target and must be carefully
taken into account. 

The FOOT experiment (*FragmentatiOn Of Target*) is designed to study these processes. Target
nuclei (16O,12C) fragmentation induced by 150-250 AMeV proton beam will be studied via inverse
kinematic approach. 16O,12C therapeutic beams, with the quoted kinetic energy, collide
on graphite and hydrocarbons target to provide the cross section on Hydrogen. This configuration
explores also the projectile fragmentation of these 16O,12C beams. The detector includes a
magnetic spectrometer based on silicon pixel detectors and drift chamber, a scintillating crystal
calorimeter with TOF capabilities, able to stop the heavier fragments produced, and a DE detector
to achieve the needed energy resolution and particle identification.

 ![detector](https://github.com/rotolanna/Software_and_Computing_Project/blob/master/Project/detector.png)

## About the code

My work is based on simulated (aka: fake) events thanks to [FLUKA](http://www.fluka.org/fluka.php) which is a fully integrated particle physics MonteCarlo simulation package.  

At first I started with the Project_00 code, which is mostly in C language. It contains the definition of the *Event* class and the main function. The Event is composed of all the variables that are related to the particle 
informations in each part of the detectors. 

In order to make the code easy for other people to use and easy to edit, I decided to split it into blocks using the classes in c ++. 
I created the first class *Initialization* which sets the experimental informations about each detectors and the beam(Z,A,Energy).
Then, I added the *Generation* class. It deals with all the quantities directly generated from MonteCarlo (taken from the ROOTple data) and fills the related plots.

I included a new  *Booking* class  to show the graphs filled by Generation.cpp and Reconstruction.cpp.

After that,  the * Reconstruction* class is created. A real case is simulated, so it needs to identify the different fragments that come out of the interaction with the target. For this aim, in the Project_01 code there are some conditions
 in order to check  which tracks pass through all the FOOT detectors, including secondary and tertiary fragments of the beam.

In order to identify the fragments, one must find the charge Z and the mass number A. I created a function that measures the parameters of the tracks, such as position, momentum and the deposited energy.  At this step, 
the Reconstruction class manipulates the MC informations using a *smearing function* and thanks to this procedure, I obtained events with data very close to the real ones.
Through these values, I implemented a way to get all the quantities which are exploited by the *BeteBloch function* to extract Z. 

NOTE: from *Reconstruction.h* :

```c++                                                                              
 
  //                                                                       H   He  Li  Be    B    C     N    O    D    T  He3

int    charge_rec_frag[NUMFRAG] = {1,   2,   3,   4,    5,    6,    7,    8,   1,   1,   2 };
```

![Z_reconstructed](https://github.com/rotolanna/Software_and_Computing_Project/blob/master/Project/Z_reconstructed.jpg).   
 Note: on y-axis, the right label is *Events*.

Then, the FOOT experiment provides  three formulas to derive A.

`A_1 = p / (U γ c β) `  

`A_2 = E_k  / (U pow(c,2) (γ - 1)) `  

` A_3 = (pow(c,2)*pow(p,2) - pow(E_k,2)) / (2 U pow(c,2) E_k) `


 The peak position is centered around the expected values with in some cases a shift completely included in the resolution;
 the latter is about 5% for A_2 and slightly worst for A_1 reconstruction modes, while it is a bit larger than 10% in the A_3 case. These resolutions depend on the input smearing applied to the time of flight, 
momentum and kinetic energy reconstruction. The calorimeter is the detector that suffers for the energy leakage so,  A_2 and A_3 present a correlated tail at low and high values respectively, dependent on the
energy leakage, especially from neutron emission inside it.
 Here the link for my [Reconstructed A.ppt](https://github.com/rotolanna/Software_and_Computing_Project/blob/master/Project/Mass%20Plot.pptx).
 Note: For heavier fragments I am still studying to understand the reason for a shift, greater than expected for A_2 and A_3.  







