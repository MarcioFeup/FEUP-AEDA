# FEUP-AEDA
Algoritmos e Estruturas de Dados ([Algorithms and Data Structures](https://sigarra.up.pt/feup/en/ucurr_geral.ficha_uc_view?pv_ocorrencia_id=436433)) proposed exercises' resolution.



### Structure:   

Inside each directory lies a exercise, like a repo of its own. 



### Libraries:

[Google unit testing framework](https://github.com/google/googletest) was used for unit testing.

Check [here](https://www.jetbrains.com/help/clion/creating-google-test-run-debug-configuration-for-test.html) for more info on unit testing.



### Documentation:

[Doxygen](http://www.doxygen.nl/) was used for documentation purposes. In order to create HTML and LaTeX documentation one should have it installed. To do so, one should follow the steps described [right here](http://www.doxygen.nl/download.html).

But, if you are using a debian based linux distro ([check them here](https://en.wikipedia.org/wiki/List_of_Linux_distributions#Debian-based)), you can simply use:

```bash
sudo apt-get install doxygen
```

After the installation, inside one exercise directory, head to the /docs sub (creating it if one does not exist already), create the _Doxyfile_ through:

```bash
doxygen -g Doxyfile
```

Edit the file, taking inspiration from [here](https://gist.github.com/ctrlMarcio/67a56bfb790e840b8a63b81361976791) (at least using its _INPUT_ and _RECURSIVE_ entries).

And then run ``` doxygen Doxyfile``` to generate the documentation.