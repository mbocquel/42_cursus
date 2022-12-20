# Eval FDF

## Preliminary tests
Minimal requirements

Does the assignment meet the minimal requirements?

- The repository isn't empty.
- Norminette shows no errors.
- No cheating.
- No forbidden function/library.
- The code compiles with the required options.
- The executable is named as expected.
- During execution, there is no brutal or unmanaged crash (segfault, bus error, and so forth).
- No memory leaks.


# Mandatory part
## Error management

Test fdf without parameters, with too many parameters, a non-existing file or on which you have no rights. If those tests are passed, then it's all good. This is the only error management that is required. For now on, the maps inside the input files have to be formatted properly.

## Graphic management
Run the program with the 42 map provided from the project page and verify that:

- A window opens
- Something is drawn in the window
- You can see a isometric projection of the 42 map
- Pressing 'ESC' closes the window and exits the program in a clean way (no leaks).
- Clicking on the cross on the window's frame closes the window and exits the program in a clean way (no leaks).

## Line tracing
Use a flat map with nothing but 0, sized 4x4. We have a flat wireframe grid with a projection that is used to give a 3D concept.
Same map, with 1 point at a different altitude. Check that the result corresponds and that the 3D effect is rendered.

## Heavy map
Check whether the program handles a bigger map and an aleatory 16x16 map.

## Heavier map
Test with bigger, heavier maps. Either those provided in the intranet, the evaluated student, or your owns. Be logical and keep in mind the requirements of the subject regarding what could contain your maps (colors for example).

## Graphic responsive
If the graphical representation stayed fluid and pleasant in the last test with heavy maps, then it's cool.

## MiniLibX images
Take a look at the code and check whether the student uses the images from the MLX to draw the image instead of putting pixels one by one. ;)

# Bonus part
A lot of nice extras.

## Extra projection
Can the map be represented using another projection (such as parallel or conic)?

## Zoooooooom
Is there a way to zoom in and out using the keyboard or mouse?

## Translate
Is there a way to translate the projection using the keyboard or mouse?

## Rotation
Is there a way to rotate the projection using the keyboard or mouse?

## Be crazy
Give one more point if there is any additional bonus you consider is fine.
Creativity is an important point in your education and in the digital world.


# Autres trucs a verifier
- Check pas l'extension des fichier (demander dans le sujet mais pas dans la grille de correction)
- Verifier memoire si le fichier commence par des lignes vides
- Gerer env -i.
- Regarder si fichier vide, ou pas de fichier. 
- Gerer comportement en cas de chmod 000 sur le fichier. 

