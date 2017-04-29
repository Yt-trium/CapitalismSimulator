manjaro:
	sudo systemctl start rpcbind.service

# Test
test:
	./build-CapitalismSimulator-Desktop-Debug/CSProducer/CSProducer 0 &
	./build-CapitalismSimulator-Desktop-Debug/CSProducer/CSProducer 5 &
	./build-CapitalismSimulator-Desktop-Debug/CSAgent/CSAgent 10 &
	./build-CapitalismSimulator-Desktop-Debug/CSAgent/CSAgent 11 &
	./build-CapitalismSimulator-Desktop-Debug/CSCoordinator/CSCoordinator 0 1 1 1 500 10000 1000 1 2000 1 0 0 0 0 0 0 0 2 0 &

H:
	./build-CapitalismSimulator-Desktop-Debug/CSAgent/CSAgent 0

testH:
	./build-CapitalismSimulator-Desktop-Debug/CSProducer/CSProducer 0 &
	./build-CapitalismSimulator-Desktop-Debug/CSProducer/CSProducer 5 &
	./build-CapitalismSimulator-Desktop-Debug/CSAgent/CSAgent 10 &
	./build-CapitalismSimulator-Desktop-Debug/CSCoordinator/CSCoordinator 1 1 0 1 500 10000 1000 1 2000 1 0 0 0 0 0 0 1 1 0 &

kill:
	pkill CSAgent
	pkill CSProducer
	pkill CSCoordinator

clean:
	rm ./build-CapitalismSimulator-Desktop-Debug/log.txt 
