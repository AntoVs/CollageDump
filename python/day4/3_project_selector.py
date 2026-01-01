def CourseSelect(a,b):
    skills = {
        'cs': {'beginner': 'Web-Based Projects', 'intermediate':'Face Recognition/recognition', 'advanced':'Secure Voting using Blockchain'},
        'mech': {'beginner': 'Stair-Climbing Trolley', 'intermediate':'E-Bike ', 'advanced':'Health Monitoring System'},
        'eee': {'beginner': 'Home Automation', 'intermediate':'IoT-Based Energy Meter', 'advanced':'Voice-Controlled Wheelchair'}
    }

    if a in skills:
        if b > 8:
            print(skills[a]['advanced'])
        elif b > 5:
            print(skills[a]['intermediate'])
        elif b > 4:
            print(skills[a]['beginner'])
        else:
            print("improve skills bruh!")
    else:
        print("invalid choice!")

a = input("Enter area of interest(cs/mech/eee): ")
b = int(input("Enter skill level(1-10): "))
CourseSelect(a,b)
