from headers import client

db = client['school']

bson = {'name': 'Tom', 'age': 9}

db.student.insert_one(bson)

res = list(db.student.find())
print(res)
