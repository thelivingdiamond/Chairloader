# Steam Deck & Linux Installation Guide
## Step 1. Install Chairloader Mod Manager
1. (Steam Deck) Switch to Desktop Mode
2. Download the latest release archive
3. Extract the archive to `/home/deck/Applications/`  
   ![image](steam-deck-and-linux/a7c305d6-3b55-41bd-93ed-03398c35c268.png)
4. Open Steam, Add a Game -> Add Non-Steam Game -> Browse...  
   ![image](steam-deck-and-linux/87d9441a-50c5-47ea-9a98-35aa2635f07d.png)
5. Browse to `ChairManager.exe`
6. Right-Click ChairManager -> Properties -> Compatibility -> Force the use of a specific Steam Play compat tool
7. Select Proton Experimental
8. Close the window and launch ChairManager.exe
9. Continue installation normally. Game may be located in:
   - Internal storage: `/home/deck/.local/share/Steam/steamapps/common/Prey`
   - SD Card: `/run/media/deck/[long id]/steamapps/common/Prey`

## Step 2. Setting up the game
1. Select Prey in Steam Library
2. Right-Click -> Properties -> General
3. Type in the launch options:
   ```
   WINEDLLOVERRIDES="mswsock.dll=n,b" %command%
   ```
4. Close the window
5. Launch Prey