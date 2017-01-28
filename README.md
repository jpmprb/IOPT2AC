# IOPT2AC
Prototype of a toolkit to generate executable code for distributed embedded controllers, based on the code generated by IOPT Tools, a cloud-based tool for model-driven development of controllers. The toolkit includes a script to change the tool generated code to allow inter-device communication though the I2C-bus specification.

![Prototype](https://raw.githubusercontent.com/arturataide/IOPT2AC/master/images/i2c_comm_prototype/distributed_controller/distributed_controller_f1.jpg)

---

### Requirements
* Python 2.7
* 2 Arduino Boads
* 1 BreadBoard
* 2 Momentary Buttons
* 2 LED's
* 2 4.7k Ohm Resistors (for I2C)
* 2 10k Ohm Resistors (for momentary buttons)
* 2 220 Ohm Resistors (for LED's)
* Hook-up wires

### IOPT-Tools

The IOPT-Tools framework allows the interactive creation of graphical models using IOPT nets. The user creates the Petri net graph and associates external signals and events to its transitions and places. Each event is defined based on the change of a signal value (edge up or edge down). The models can be interactively simulated [11] and its state space generated and verified to detect deadlocks, determine needed memory resources, and identify the occurrence of desirable global states [12]. The nodes can have distinct associated time domains. These models can be automatically split in the corresponding single time domain models from which code is then generated to be run in distinct processors [13], [14], [15]. In this prototype it is possible to run those nets on Arduino boards.

For more informations on how to use IOPT-Tools framework please read it's [user manual].

#### Model Creation
For proof of concept there were created two models, one with a single time domain (single controller needed) and another with two distinct time domais (two controllers needed).

With [IOPT Tools] it is possible to open the models present on the [models folder] with the "Upload Model File" feature.
Since the user has the model opened the C language code can be generated with a click in "Generate C Code" button, as seen in the following figure.

![Generate C Code](https://dl.dropboxusercontent.com/u/66156156/i2c%20paper/generate_c_code.png)

This is the example for a single controller model, and the code generated is available [here].

For the N-time domain models an aditional step needs to be done. The user must generate the GALS Models (Globally-Asynchronous Locally-Synchronous) first with the "Decompose GALS" button. The framework will automatically generate N new models as the N is equal to the time domains present in the model.
With two time domains (proof of concept example) it will generate two models as seen in the following figure.

![GALS Models](https://dl.dropboxusercontent.com/u/66156156/i2c%20paper/gals.png)

In order to obtain the C code the user has to access every GALS Model ad press the "Generate C Code" button.
This model code is present in [this folder] named as "distributed_GALS_1.zip" and "distribited_GALS_2.zip".

#### Prepare the arduino project
Please follow this steps to prepare the arduino project:

##### Step1
Unzip the generated C Code file and delete the files `MakeFile`, `http_server.h`, `http_server.c`, `dummy_gpio.c`, `linux_sys_gpio.c`, `raspi_mmap_gpio.c`, `net_dbginfo.c`,  `net_server.h` and `net_server.c`.
```sh
$ rm MakeFile http_server.* dummy_gpio.c linux_sys_gpio.c raspi_mmap_gpio.c net_server.*
```

##### Step2
Rename the `net_main.c` file to its parent folder name and change its extension to `.ino`.
 ```sh
 $  mv net_main.c single_controller.ino
 ```

 ##### Step3
 Run the IOPT2AC script passing the input (`-i`) file and output (`-o`) file arguments.
 The input file must be the `net_io.c` file and the output file must have `.cpp` extension in other to fully support `Wire.h` [library]. After running the script please remove the `net_io.c` file.
 ```sh
 $ python IOPT2AC_distributed.py -i net_io.c -o net_io.cpp
 $ rm net_io.c
 ```

 ##### Step3 - Single Controller
 In the single controller scenario the script used is the [IOPT2AC_single.py]. When the script finishes to run it outputs where the arduino's Digital Ports should be connected.
 ```sh
 Inputs
Digital 2 -> net1
Digital 3 -> net2
2
Outputs:
Digital 4 -> led1
Digital 5 -> led2
2
Input Events:
[]
0
Output Events:
[]
0
 ```

 ##### Step3 - Distributed Controllers
 In the single controller scenario the script used is the [IOPT2AC_distributed.py]. This step needs to be done as many times as there are GALS Models.
 In this script the user as to introduce the I2C addresses of the arduino boards.
 ```sh
Inputs
Digital 2 -> net1
Digital 3 -> net2
2
Outputs:
Digital 4 -> led1
1
Input Events:
['event20']
1
Output Events:
['event19']
1
Enter this device address: 1
Enter the address of event19 device: 2
Addresses
[{'event': 'event19', 'address': '2'}]
```
![Workflow](https://dl.dropboxusercontent.com/u/66156156/i2c%20paper/workflow.png)

***NOTE:*** The IOPT2AC script has two versions, one for the single controller example and another to the distributed controllers example. Please run the one that applies to you model scenario.

 ##### Step4
 ***Note:*** You can skip the previous steps and compile the already [prepared code] with [Arduino IDE]

 Setup the Arduino board and the breadboard with the required components as the next figures show:

 ##### Step4 - Single Controller
 ![Single Controller Design](https://raw.githubusercontent.com/arturataide/IOPT2AC/master/images/i2c_comm_prototype/single_controller/single_controller_design.png)
 ##### Step4 - Distributed Controller
 ![Distributed Controller Design](https://raw.githubusercontent.com/arturataide/IOPT2AC/master/images/i2c_comm_prototype/distributed_controller/distributed_controller_design.png)

The user can see the models beaviour with the Serial Monitor at 9600 bitrate.

For any questions with the preparation and setup please contact arturjataide@gmail.com.

License
----
???

   [user manual]: <http://gres.uninova.pt/iopt_usermanual.pdf>
   [IOPT Tools]: <http://gres.uninova.pt/IOPT-tools/>
   [models folder]: <https://github.com/arturataide/IOPT2AC/tree/master/models>
   [here]:<https://github.com/arturataide/IOPT2AC/blob/master/code/single_controller/single_controller.zip>
   [this folder]: https://github.com/arturataide/IOPT2AC/tree/master/code/distributed_controller>
   [library]: <https://www.arduino.cc/en/Reference/Wire>
   [IOPT2AC_single.py]: <https://github.com/arturataide/IOPT2AC/blob/master/code/single_controller/IOPT2AC_single.py>
   [IOPT2AC_distributed.py]: <https://github.com/arturataide/IOPT2AC/blob/master/code/distributed_controller/IOPT2AC_distributed.py>
   [prepared code]: <https://github.com/arturataide/IOPT2AC/tree/master/code/distributed_controller/ReadyToArduino>
   [Arduino IDE]: <https://www.arduino.cc/en/main/software>
