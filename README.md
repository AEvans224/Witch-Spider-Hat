# Witch-Spider-Hat
Witch costume hat that has spiders constantly moving up and down the hat brim. This little project was a fun addition to my mom's witch costume for Halloween. As an electrical engineer, the electronics parts and software came more naturally to me, but the 3D model could use some improvements (learning is the best!). The files are still available to download if your witch hat is 7.5 inches in diameter. Please note that the hardest part of this project is overcoming the friction on the physical hat and making sure the spiders weigh enough to keep the tension. Through trial and error, I learned that coffee straws have a very small friction coefficient and the spiders needed magnets inside to help weight them down.  
<img width="590" height="1278" alt="IMG_5065" src="https://github.com/user-attachments/assets/08367293-5a0c-4292-b359-830d5b69ac6e" />
<img width="590" height="1278" alt="IMG_5064" src="https://github.com/user-attachments/assets/7893217a-1354-477b-9946-ba98133a0f13" />

## Bill of Materials:
- Battery (7.4V 2000mAh URGENEX)
- Buck Converter (QTY 2) (LM2596
- Switch
- Fuse (1A)
- Motor Driver (Dual TB6612FNG (1A))
- Motor (Pololu 50:1 6V Gearmotor #2365)
- Microcontroller (Arduino Nano)
- 3D Printer Filament (Bambu Labs PLA)
- Clear string (Fishing wire)
- Glue (Gorilla Glue)
- Witch's Hat
- Coffee Straws
- Magnets

## 3D Print Files:
The stl files are located in the 3D model folder.
<img width="761" height="594" alt="Screenshot 2026-10-12 205430" src="https://github.com/user-attachments/assets/4cac1967-1848-4ac2-b4f0-3ba76efa7210" />

## Component Preparation:
Using a power supply and multimeter, the buck converter's potentiometer was adjusted to output 5V and 6V. 

## Wiring Diagram:
The connections summary section of the wiring diagram is correct. ChatGPT helped to create the diagram so there are some inconsistences with the wire to wire drawing. However, the basic concepts are still demonstrated and I felt like the diagram was helpful to understand the placement of parts when I designed the 3D model. 
<img width="1536" height="1024" alt="248fc0c1-056d-44cf-bcb0-2db88b23d25c" src="https://github.com/user-attachments/assets/a743f1fe-98be-4f55-90d3-54464f32e229" />

## Assembly:
The assembly should look like the CAD model above. Use gorilla glue to secure the spools onto the shaft. Use the 3D printed cylindrical stubs to connect the hoop to the robotic hat. The hoop is attached to the hat by sewing strong thread through the small four holes around the brim or gluing the hoop to the witches hat brim. Insert the fishing wire through the guides onto the spool and glue the wire to the spools. Thread the other side of the fishing wire through the coffee straws and off the edge of the witches hat.  

<img width="500" height="700" alt="IMG_5016" src="https://github.com/user-attachments/assets/1981280d-ce49-4a56-8267-890ca1ca9aa6" />

## Software:
The software is written in the Arduino C++ file type .ino. The speed and time variables will change the spider's distance and speed. As a note, the type of motor used does not "remember" the last position, so it is always going to start over the code. Verify that the spiders are in the furthest down position before turning off the power to the system. 
