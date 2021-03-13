//
// Created by RodrigoSalad on 11/03/2021.
//

#ifndef CUSTOMBREAKER_ARGS_INTERPRETER_H
#define CUSTOMBREAKER_ARGS_INTERPRETER_H

#include "common_types.h"


namespace cb{
    namespace args_intr{
        // Args Interpreter Functor

        // Custom types
        using args_t = cb::string_t;
        using args_dict = cb::dict<args_t, args_t>;

        // Functor
        class SimpleArgsCollector{
        private:
            // Utility methods
            static void validate_flag(const args_t& flag){
                if (flag.empty()){cb::error_exit<127>( "FLAG VACIA" );}
                if (flag[0]!='-'){cb::error_exit<127>( "ARGUEMNTO '",flag,"' NO ES FLAG" );}
            }
            static void validate_size(const cb::size_t& indx, const cb::size_t& argc){
                if (indx >= argc){cb::error_exit<125>("PARAM FUERA DE RANGO n: ", indx);}
            }
            static cb::size_t evalute_type(const args_t& arg) {
                return arg.find('=');
            }
            static void process_eqflag(const args_t& c_arg, cb::size_t pos , args_dict& return_dict){
                args_t flag = c_arg.substr(0, pos);
                args_t parm = c_arg.substr(pos+1);
                return_dict[flag] = parm;
            }
            static void process_spflage(const args_t& flag, const args_t& parm, args_dict& return_dict){
                return_dict[flag] = parm;
            }
        public:
            // Constructor = Default
            SimpleArgsCollector() = default;
            // Operator
            args_dict operator() (const int &argc, char** argv);
        };

        // Functor
        class LinkedArgsCollector{
        private:
            // Atributes
            args_dict &linked_dict;
            // Update/Processing methods
            void update_pair(const args_t& flag, const args_t& parm){
                auto it = linked_dict.find(flag);
                if ( it == linked_dict.end()) {cb::error_exit<127>( "FLAG - '",flag,"'  NO EXISTE" );}
                else {it->second = parm;}
            }
            void process_eqflag(const args_t& c_arg, cb::size_t pos){
                args_t flag = c_arg.substr(0, pos);
                args_t parm = c_arg.substr(pos+1);
                update_pair(flag, parm);
            }
            void process_spflage(const args_t& flag, const args_t& parm){
                update_pair(flag, parm);
            }
            // Utility methods
            static void validate_flag(const args_t& flag){
                if (flag.empty()){cb::error_exit<127>( "FLAG VACIA" );}
                if (flag[0]!='-'){cb::error_exit<127>( "ARGUEMNTO '",flag,"' NO ES FLAG" );}
            }
            static void validate_size(const cb::size_t& indx, const cb::size_t& argc){
                if (indx >= argc){cb::error_exit<125>("PARAM FUERA DE RANGO n: ", indx);}
            }
            static cb::size_t evalute_type(const args_t& arg) {
                return arg.find('=');
            }
        public:
            // Constructor: Parameter -> Linked dict
            explicit LinkedArgsCollector(args_dict& in) : linked_dict{in} {};
            // Operator
            void operator() (const int &argc, char** argv);
        };

        // Short names
        using SimpleAC = SimpleArgsCollector;
        using LinkedAC = LinkedArgsCollector;
    }
}


#endif //CUSTOMBREAKER_ARGS_INTERPRETER_H
