Racetrack memory RTL model
==========================
This folder contains all the RTL files of the Racetrack memory.

Memory organization
--------------------------
In the following a brief insight of the hierarchical architecture of the memory will be given.
The Racetrack memory array is made up by multiple basic elements called Blocks, the required number of Blocks is istantiated automatically based on the memory size. the file `RT_memory` intantiates the required number of Blocks based on the memory parameters.
Each block is internally divided in multiple Macro Units, 32x32 bits arrays composed by several Racetracks. The file `RT_block` instantiates the required number of Macro Units based on the memory parameters, then hierarchically the file `RT_32_8_4_MU` instantiates all the required Racetracks.
The Racetrack has a 3D structure composed by four different Racetracks:
* Logic Racetrack : computes and stores LiM results
* Data Racetrack : stores standard Data
* Mask Racetrack : stores Mask values
* Program Racetrack : stores program bit 

The file `RT_32_8_4_line` instantiates all the basic Racetrack cells (`pNML_NAND_NOR`, `pNML_NAND_NOR_SOT`, `RT_cell`, `RT_read_write_SOT`) for each of the four different Racetracks.

<img src="./images/RT_32_8_4_profile_3D.png" align="center" width="80%" height="80%">

Memory architecture
--------------------------
The Racetrack array is instantiaed in the file `RT_memory` which wraps the raw memory core and adds surrounding logic for the correct functioning (i.e. `FSM` and `shifter` modules), this module includes also all the logic required for the LiM computations. 

<img src="./images/racetrack_array_arch.png" align="center" width="50%" height="50%">

The Racetrack memory is instantiated by the file `dp_ram_logic`, which provides all the additional logic (i.e. decoders, shift number generator etc.).

<img src="./images/racetrack_memory_arch.png" align="center" width="50%" height="50%">

Word organization
--------------------------
The Racetrack memory is capable of parallel LiM store operations by performing parallel accesses in each Block. This feature requires a different word organizayion within the memory.

<img src="./images/word_organization.png" align="center" width="25%" height="25%">




