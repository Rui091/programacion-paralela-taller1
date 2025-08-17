#!/bin/bash
# Uso: ./decrypt_it.sh <shift> "texto"

if [ $# -lt 2 ]; then
  echo "Uso: $0 <rotacion> \"texto\""
  exit 1
fi

shift_val=$1
text=$2

# Para descifrar se rota en sentido contrario
ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
abc="abcdefghijklmnopqrstuvwxyz"

# Rotación inversa (26 - shift)
inv_shift=$((26 - shift_val))
ABC_SHIFT=$(echo $ABC$ABC | cut -c$((inv_shift+1))-$((inv_shift+26)))
abc_SHIFT=$(echo $abc$abc | cut -c$((inv_shift+1))-$((inv_shift+26)))

echo "$text" | tr "A-Z" "$ABC_SHIFT" | tr "a-z" "$abc_SHIFT"
