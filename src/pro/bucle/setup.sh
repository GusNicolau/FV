#chmod a+x setup.sh
#./setup.sh
#!/bin/bash
# URL del archivo .zip en Google Drive
file_url="https://drive.usercontent.google.com/download?id=1v9gREc4ECrkE1syDHrl98z0r_MDNskYx&export=download&authuser=0&confirm=t&uuid=a847c415-81d3-449e-b87c-44f22288cc78&at=APZUnTUw5zxiAttVnSMWW5fld8N7:1716286197639"
# Nombre del archivo .zip
file_name="resources.zip"
# Nombre del directorio de destino para la extracción
extract_dir="resources"
# Descarga el archivo .zip utilizando wget
wget "$file_url" -O "$file_name" --no-check-certificate
# Notifica al usuario que la descarga ha sido completada
echo "Descarga completada: $file_name"
# # Crea el directorio de destino si no existe
mkdir -p "$extract_dir"
# # Descomprime el archivo .zip en el directorio de destino
unzip -FF "$file_name" -d "$extract_dir"
# # Notifica al usuario que la extracción ha sido completada
echo "Extracción completada en: $extract_dir"