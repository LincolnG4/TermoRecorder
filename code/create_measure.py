
from csv import reader
from openpyxl import Workbook
from sys import argv
from os import mkdir,path

#Comentarios 
folder_measures='measures'
droppedFile = argv

for rawfile in droppedFile[1:]:
    print('Reading file: %s'%(rawfile))
    with open(rawfile,'r') as file:
        measure = [ row for row in reader(file) if row != [] ]

    wb = Workbook()
    ws1 = wb.active

    ws1.title = "%s_measure_1"%((rawfile.split('\\')[-1]).split('.')[0])
    
    dest_filename = '%s.xlsx'%((rawfile.split('\\')[-1]).split('.')[0])
    key=0

    for y,x in enumerate(measure):
        if float(x[0]) == 0.0:
            key += 1
            if key >= 2:
                ws1 = wb.create_sheet(title="%s_measure_%s"%((rawfile.split('\\')[-1]).split('.')[0],key)) 
        if x[1].strip() == 'NAN':
            x[1] = None

        ws1.append(x)

    try:
        mkdir('./%s'%(folder_measures))
        print('Folder created: ./%s'%(folder_measures))
    except:
        pass
    
    
    wb.save(filename = path.join(folder_measures,dest_filename))
    print('Measure file created: %s'%(path.join(folder_measures,dest_filename)))

input('Press ENTER to exit...')