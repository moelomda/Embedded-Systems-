# AVR ATmega32 Drivers Repository

## Overview

This repository contains drivers and libraries for the AVR ATmega32 microcontroller. The drivers are organized into four main folders: **LIB**, **MCAL**, **HAL**, and **APP**. Each folder serves a specific purpose in organizing the codebase.

## Folder Structure

### 1. LIB (Library)

The **LIB** folder contains general-purpose libraries that can be used across different projects. These libraries provide common functionalities that are not specific to a particular application.

### 2. MCAL (Microcontroller Abstraction Layer)

The **MCAL** folder contains the Microcontroller Abstraction Layer, which abstracts the hardware-specific details of the ATmega32 microcontroller. It includes low-level drivers for peripherals such as GPIO, Timer/Counter, USART, etc. These drivers provide a consistent interface to interact with the microcontroller's hardware.

### 3. HAL (Hardware Abstraction Layer)

The **HAL** folder houses the Hardware Abstraction Layer, which abstracts higher-level functionalities and peripherals. It provides a more user-friendly interface compared to the **MCAL** layer. Users can interact with the hardware using functions provided by the **HAL** layer without worrying about low-level details.

### 4. APP (Application)

The **APP** folder contains example applications or projects that utilize the drivers provided in the **LIB**, **MCAL**, and **HAL** layers. These applications showcase how to use the drivers for specific use cases. Users can refer to these examples as a starting point for their own projects.

## How to Use

1. **Clone the Repository:**

   ```
   bashCopy code
   git clone https://github.com/moelomda/Embedded-Systems-
   ```

2. **Navigate to Desired Folder:**

   

3. **Explore the Code:**

   - **LIB**: General-purpose libraries.
   - **MCAL**: Low-level microcontroller abstraction layer.
   - **HAL**: Higher-level hardware abstraction layer.
   - **APP**: Example applications.

4. **Incorporate into Projects:**

   - Copy relevant files into your AVR ATmega32 project.
   - Include necessary headers.
   - Utilize functions from **LIB**, **MCAL**, and **HAL** layers as needed.

## License

This repository is licensed under the MIT License - see the LICENSE file for details.
