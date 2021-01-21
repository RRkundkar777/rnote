cp -r v1.0.0_linux $HOME/RNote
cp $HOME/RNote/RNote.desktop $HOME/Desktop/RNote.desktop
cp ./Images/RNote.png $HOME/RNote/RNote.png


sed -i "4i4 Exec=$HOME/RNote/RNote/" $HOME/Desktop/RNote.desktop
sed -i "5i5 Icon=$HOME/RNote/Images/RNote.png/" $HOME/Desktop/RNote.desktop 

echo "RNote Installed Successfully"
