# Royal Kludge r65 ISO (Only Wired)
![Royal Kludge R65 Keyboard](r65iso.png)

### Select Language: 
- [ENGLISH](#english)
- [ESPAÑOL](#español)

---
<a name="english"></a>

<div align="center">
  English Section:
</div>

>[!IMPORTANT]  
>⚠️ These files are only for the **ISO** wired version of the **Royal Kludge R65** keyboard. These files **MUST NOT** be used for the wireless version.
>🛑 
>📜 You **MUST READ THE [DISCLAIMER](DISCLAIMER-ENG.md)** provided, available in both English and Spanish, containing in-depth relevant explanations before using the files in this repository.

## Description 🖋️  
📂 Most of the files in this repository remain unmodified from the original work of *[sdk66](https://github.com/sdk66), [irfanjmdn](https://github.com/irfanjmdn), and [iamdanielv](https://github.com/iamdanielv)*. These codes have been properly **credited** and retain their original implementation to honor the merit of the authors.

✨ Feel free to check out their projects to learn more about their work! 💡 [^1][^2][^3]

🛠️ My contribution involved selecting the most notable aspects of their developments and making minor adjustments to some files.  
📄 The main exception is the *[keymap.c](rk/r65/keymaps/iso/keymap.c)* file, which **was significantly modified**. In this file, I **adapted the layout to the ISO standard** and fixed errors related to key mapping.

✨ I hope this can be useful to someone someday! 💡  

## Guide

### > 🏗 Building the Firmware

1. **Install QMK MSYS**  
   Download and install [QMK MSYS](https://msys.qmk.fm).

2. **Set Up QMK MSYS**  
   Open QMK MSYS and run the command:  
   ```bash
   qmk setup
   ```
   A folder will be installed at `C:/Users/%USERNAME%/qmk_firmware`.

3. **Add Keyboard Files**
   Download this repository and move the `rk/r65` folder into your `qmk_firmware/keyboards/` folder.

5. **Compile the Firmware**  
   Run the following command in QMK MSYS:  
   ```bash
   qmk compile -kb rk/r65 -km iso
   ```  
   (Only iso version available)

6. **Locate the Firmware File**  
   Find the compiled `.bin` or `.hex` file in the root of the `qmk_firmware` folder.

### > ⚡ Flashing/Installing the Firmware

1. **Install QMK Toolbox**  
   Download and install [QMK Toolbox](https://github.com/qmk/qmk_toolbox/releases).

2. **Load the Firmware File**  
   Open QMK Toolbox and load the `.bin` or `.hex` file.

3. **Enter Bootloader Mode**  
   Reset the keyboard into bootloader mode.

4. **Flash the Firmware**  
   Click 'Flash', then 'Exit DFU' once the flashing process is complete.

### > 🔓 Entering Bootloader Mode

- **Option 1**: Hold the Reset switch on the PCB while connecting the USB cable.
- **Option 2**: Hold the Escape key while connecting the USB cable (this will also erase settings).
- **Option 3**: Press `Fn+Shift+Esc`.
---
<a name="español"></a>

<div align="center">
  Sección en Español:
</div>

>[!IMPORTANT]  
>⚠️ Estos archivos son solo para la versión **ISO** cableada del teclado **Royal Kludge R65**. Estos **NO** deben ser usados para la versión inalámbrica.  
>🛑 Esto es **firmware custom** que podría romper tu teclado, use bajo su propio riesgo.  
>📜 Usted **DEBE LEER EL [DISCLAIMER](DISCLAIMER-ESP.md)** otorgado, está tanto en Español como en Inglés y contiene explicaciones a fondo relevantes antes del uso de los archivos de este Repositorio.

## Descripción 🖋️  
📂 La mayoría de los archivos de este repositorio se mantienen sin modificaciones respecto al trabajo original de los desarrolladores *[sdk66](https://github.com/sdk66), [irfanjmdn](https://github.com/irfanjmdn) y [iamdanielv](https://github.com/iamdanielv)*. Estos códigos han sido debidamente **acreditados** y conservan su implementación original para respetar el mérito de los autores.

✨ ¡Te invito a echar un vistazo a sus proyectos para conocer más sobre su trabajo! 💡 

🛠️ Mi contribución consistió en seleccionar los aspectos más destacados de sus desarrollos y realizar ajustes menores en algunos archivos.  
La excepción principal es el archivo *[keymap.c](rk/r65/keymaps/iso/keymap.c)*, que **fue significativamente modificado**. En este archivo, **adapté el diseño al estándar ISO** y corregí errores relacionados con el mapeo de las teclas.

✨ ¡Espero que le pueda ser de utilidad a alguien algún día! 💡  

## Guía

### > 🏗 Construcción del Firmware

1. **Instalar QMK MSYS**  
   Descarga e instala [QMK MSYS](https://msys.qmk.fm).

2. **Configurar QMK MSYS**  
   Abre QMK MSYS y ejecuta el siguiente comando:  
   ```bash
   qmk setup
   ```
   Esto instalará una carpeta en `C:/Users/%USERNAME%/qmk_firmware.`

3. **Añadir Archivos del Teclado**  
  Descarga este repositorio y mueve la carpeta `rk/r65` dentro de tu carpeta `qmk_firmware/keyboards/`.

4. **Compilar el Firmware**  
   Ejecuta el siguiente comando en QMK MSYS:
   ```bash
   qmk compile -kb rk/r65 -km iso
   ```
   (Solo está disponible la versión ISO)

5. **Localizar el Archivo de Firmware**  
   Encuentra el archivo compilado `.bin` o `.hex` en la carpeta raíz de `qmk_firmware`.

### > ⚡ Flasheo/Instalación del Firmware
1. **Instalar QMK Toolbox**  
   Descarga e instala [QMK Toolbox](https://github.com/qmk/qmk_toolbox/releases).

2. **Cargar el Archivo de Firmware**  
   Abre QMK Toolbox y carga el archivo `.bin` o `.hex`.

3. **Entrar en Modo Bootloader**  
   Reinicia el teclado en modo bootloader.

4. **Flashear el Firmware**  
   Haz clic en 'Flash', luego en 'Exit DFU' una vez que el proceso de flasheo haya finalizado.

### > 🔓 Entrar en Modo Bootloader  
- **Opción 1**: Mantén presionado el interruptor de reinicio en la PCB mientras conectas el cable USB.
- **Opción 2**: Mantén presionada la tecla Escape mientras conectas el cable USB (esto también borrará la configuración).
- **Opción 3**: Presiona `Fn+Shift+Esc`.

[^1]: @irfanjmdn 's & @iamdanielv 's original ANSI rk65 project [HERE](https://github.com/irfanjmdn/r65/tree/master) with support for VIA, Vial, SignaRGB, SnapTap!.
[^2]: @sdk66 ’s QMK Firmware Repo, [HERE](https://github.com/hangshengkeji/qmk_firmware/tree/master/keyboards/rk).
[^3]: @iamdanielv 's customized firmware for the ANSI r65 [HERE](https://github.com/iamdanielv/kb_rk_r65)
