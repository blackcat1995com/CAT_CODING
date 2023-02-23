from headers import client

db = client['school']

# res = list(db.student.find({'name': 'Tom'}))
# res = db.student.find_one({'name': 'Tom'}, {'_id':0, 'age': 0})

res = db.student.find_one({'name': 'Tom'}, {'name':1, 'age': 1})
print(res)
