#!/bin/bash

# 🎨 Script para descargar assets de Flappy Bird
# Descarga automáticamente los sprites necesarios para el Ejercicio 5

echo "🎮 Descargando assets de Flappy Bird..."
echo ""

# Verificar si estamos en el directorio correcto
if [ ! -d "assets" ]; then
    echo "❌ Error: Debes ejecutar este script desde el directorio raíz del proyecto"
    exit 1
fi

# Crear directorio temporal
echo "📁 Creando directorio temporal..."
git clone https://github.com/samuelcust/flappy-bird-assets.git temp_assets

# Verificar que la descarga fue exitosa
if [ ! -d "temp_assets" ]; then
    echo "❌ Error: No se pudo clonar el repositorio"
    exit 1
fi

# Copiar sprites necesarios
echo "📋 Copiando sprites..."
cp temp_assets/sprites/bluebird-midflap.png assets/sprites/ 2>/dev/null && echo "✅ Pájaro copiado" || echo "⚠️  No se pudo copiar el pájaro"
cp temp_assets/sprites/pipe-green.png assets/sprites/ 2>/dev/null && echo "✅ Tubería copiada" || echo "⚠️  No se pudo copiar la tubería"
cp temp_assets/sprites/background-day.png assets/sprites/ 2>/dev/null && echo "✅ Fondo copiado" || echo "⚠️  No se pudo copiar el fondo"
cp temp_assets/sprites/base.png assets/sprites/ 2>/dev/null && echo "✅ Suelo copiado" || echo "⚠️  No se pudo copiar el suelo"

# Limpiar directorio temporal
echo "🧹 Limpiando archivos temporales..."
rm -rf temp_assets

echo ""
echo "✅ ¡Descarga completada!"
echo ""
echo "📂 Sprites disponibles en: assets/sprites/"
echo "🎮 Ahora puedes compilar y ejecutar el juego con:"
echo "   ./run build"
echo "   ./build/game"
