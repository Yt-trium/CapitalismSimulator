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
	./build-CapitalismSimulator-Desktop-Debug/CSCoordinator/CSCoordinator 1 1 1 1 500 10000 1000 1 2000 1 0 0 0 0 0 0 1 1 0 &

kill:
	pkill CSAgent
	pkill CSProducer
	pkill CSCoordinator

clean:
	rm ./build-CapitalismSimulator-Desktop-Debug/log.txt

stressTest:
	./build-CapitalismSimulator-Desktop-Debug/CSProducer/CSProducer 0 &
	./build-CapitalismSimulator-Desktop-Debug/CSProducer/CSProducer 1 &
	./build-CapitalismSimulator-Desktop-Debug/CSProducer/CSProducer 2 &
	./build-CapitalismSimulator-Desktop-Debug/CSProducer/CSProducer 3 &
	./build-CapitalismSimulator-Desktop-Debug/CSProducer/CSProducer 4 &
	./build-CapitalismSimulator-Desktop-Debug/CSProducer/CSProducer 5 &
	./build-CapitalismSimulator-Desktop-Debug/CSProducer/CSProducer 6 &
	./build-CapitalismSimulator-Desktop-Debug/CSProducer/CSProducer 7 &
	./build-CapitalismSimulator-Desktop-Debug/CSProducer/CSProducer 8 &
	./build-CapitalismSimulator-Desktop-Debug/CSProducer/CSProducer 9 &
	./build-CapitalismSimulator-Desktop-Debug/CSProducer/CSProducer 10 &
	./build-CapitalismSimulator-Desktop-Debug/CSProducer/CSProducer 11 &
	./build-CapitalismSimulator-Desktop-Debug/CSProducer/CSProducer 12 &
	./build-CapitalismSimulator-Desktop-Debug/CSProducer/CSProducer 13 &
	./build-CapitalismSimulator-Desktop-Debug/CSProducer/CSProducer 14 &
	./build-CapitalismSimulator-Desktop-Debug/CSProducer/CSProducer 15 &
	./build-CapitalismSimulator-Desktop-Debug/CSProducer/CSProducer 16 &
	./build-CapitalismSimulator-Desktop-Debug/CSProducer/CSProducer 17 &
	./build-CapitalismSimulator-Desktop-Debug/CSProducer/CSProducer 18 &
	./build-CapitalismSimulator-Desktop-Debug/CSProducer/CSProducer 19 &
	./build-CapitalismSimulator-Desktop-Debug/CSProducer/CSProducer 20 &
	./build-CapitalismSimulator-Desktop-Debug/CSProducer/CSProducer 21 &
	./build-CapitalismSimulator-Desktop-Debug/CSProducer/CSProducer 22 &
	./build-CapitalismSimulator-Desktop-Debug/CSProducer/CSProducer 23 &
	./build-CapitalismSimulator-Desktop-Debug/CSProducer/CSProducer 24 &
	./build-CapitalismSimulator-Desktop-Debug/CSAgent/CSAgent 10 &
	./build-CapitalismSimulator-Desktop-Debug/CSAgent/CSAgent 11 &
	./build-CapitalismSimulator-Desktop-Debug/CSAgent/CSAgent 12 &
	./build-CapitalismSimulator-Desktop-Debug/CSAgent/CSAgent 13 &
	./build-CapitalismSimulator-Desktop-Debug/CSAgent/CSAgent 14 &
	./build-CapitalismSimulator-Desktop-Debug/CSAgent/CSAgent 15 &
	./build-CapitalismSimulator-Desktop-Debug/CSAgent/CSAgent 16 &
	./build-CapitalismSimulator-Desktop-Debug/CSAgent/CSAgent 17 &
	./build-CapitalismSimulator-Desktop-Debug/CSAgent/CSAgent 18 &
	./build-CapitalismSimulator-Desktop-Debug/CSAgent/CSAgent 19 &
	./build-CapitalismSimulator-Desktop-Debug/CSCoordinator/CSCoordinator 1 1 1 1 500 10000 1000 5 2000 5 1000 5 8000 5 8000 5 0 10 0 &
