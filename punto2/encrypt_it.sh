#!/bin/bash
# Uso: ./encrypt_it.sh <shift> "texto"

if [ $# -lt 2 ]; then
  echo "Uso: $0 <rotacion> \"texto\""
  exit 1
fi

shift_val=$1
text=$2

# Alfabeto normal
ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
abc="abcdefghijklmnopqrstuvwxyz"

# Rotar el alfabeto usando cut
ABC_SHIFT=$(echo $ABC$ABC | cut -c$((shift_val+1))-$((shift_val+26)))
abc_SHIFT=$(echo $abc$abc | cut -c$((shift_val+1))-$((shift_val+26)))

# Reemplazar letras
echo "$text" | tr "A-Z" "$ABC_SHIFT" | tr "a-z" "$abc_SHIFT"
