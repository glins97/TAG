
src = ''
with open('input_teachers') as f:
    src = f.read()

data = src.split('\n')

with open('output_teachers', 'w') as f:
    for index, line in enumerate(data):
        if line.strip() == '': continue

        teacher, schools = line.split(':')
        teacher = teacher.split(',')
        schools = schools.split(',')
        for index_, param in enumerate(teacher):
            teacher[index_] = param.strip().replace("(", "").replace(")", "")
        
        for index_, param in enumerate(schools):
            schools[index_] = param.strip().replace("(", "").replace(")", "")

        while len(schools) < 4:
            schools.append("None")
        
        f.write(' '.join(teacher + schools) + '\n')

with open('input_schools') as f:
    src = f.read()
data = src.split('\n')
with open('output_schools', 'w') as f:
    for index, line in enumerate(data):
        if line.strip() == '': continue

        school, preferences = line.split(':')
        school = school.strip().replace("(", "").replace(")", "")
        preferences = preferences.split(',')
        
        for index_, param in enumerate(preferences):
            preferences[index_] = param.strip().replace("(", "").replace(")", "")

        while len(preferences) < 2:
            preferences.append("0")
        
        f.write(' '.join([school] + preferences) + '\n')



