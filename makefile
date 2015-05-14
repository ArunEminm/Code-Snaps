all:add

init:
	git init
	git remote add origin https://github.com/ArunEminm/codesnaps.git
pull:
	git pull origin master
add:
	git add --all
commit:
	git commit -a -m "__`date`"
push:
	git push origin master
fpush:
	git push -f origin master
reset:
	rm -rf .git
	make init
	make all
	make commit
	make fpush
