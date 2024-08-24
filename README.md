# Backup Script 

The script can make backup of files in ```<src>``` directory which have vowels in their name into ```<dest>``` directory maintaining the directory structure as seen in the ```<src>``` directory.    

## Crontab running

To run this script exactly at midnight 12 everyday, we are going to add a Cronjob for the user who is backing up the files. 
```bash
   0 0 * * *  ./backup_script.sh -s <src> -d <dest> -o <output>
```
The above command adds a Cronjob for the user, which runs the ```backup_script.sh``` automatically at midnight 12.  

## Working
The script takes arguments of the source directory, destination directory and also the output csv file. The script ```backup_script.sh``` goes through all the files in the ```<src>``` directory recursively using ```find``` command with the help of flags ```-type f``` for only files and ```-name``` for only name of the file to be checked for regular expression. Using ```sed```, we create the required destination path to the backup file and check if the source file is newer than the backup file, if it exists. If the backup file doesn't exist then the ```-nt``` test automatically detects that. Now  ```cp``` command gets executed when it is new and the required file is backed up.  
The file keeps track of the count of the number of files copied and the time taken is calculated using ```date``` command. ```$$``` gives PID of the process. We output all of these into the output file in CSV format. The time for running the script is in milliseconds. 
